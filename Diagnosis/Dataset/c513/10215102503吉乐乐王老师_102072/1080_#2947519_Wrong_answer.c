#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1001
void stoi(char s[],int a[]){
    int n=strlen(s)-1;
    int m=N-1;
    while(n>=0){
        a[m]=s[n]-'0';m--;n--;
    }
}
int ctn(int a[]){
    for(int i=N-1;i>=0;i--){
        if(a[i]!=0)return 1;
    }
    return 0;
}
void minus(int a[]){
    int i=0;
    while(a[i]==0)i++;
    int rmd=0;
    while(i<N){
        int temp=a[i]+rmd*10;
        a[i]=temp/2;
        rmd=temp%2;
        i++;
    }
}
void mult(int q[],int n){
    for(int i=N-1;i>0;i--)q[i]*=n;
    for(int i=N-1;i>0;i--){
        q[i-1]+=q[i]/10;
        q[i]%=10;
    }
}
void add(int dec[],int q[]){
    for(int i=N-1;i>0;i--){
        dec[i]+=q[i];
        dec[i-1]+=dec[i]/10;
        dec[i]%=10;
    }
}
int main(){
    int t;scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        char s[N];int a[N]={0};
        scanf("%s",s);getchar();
        stoi(s,a);
        int bin[N]={0};int idx=N-1;
        while(ctn(a)){
            if(a[N-1]%2){
                minus(a);
                bin[idx--]=1;
            }
            else{
                minus(a);
                bin[idx--]=0;
            }
        }
        int dec[N]={0};
        int q[N]={0};q[N-1]=1;
        if(bin[idx+1])dec[N-1]=1;
        for(int i=idx+2;i<N;i++){
            mult(q,2);
            if(bin[i])add(dec,q);
        }
        printf("case #%d:\n",cas++);
        int i=0;
        while(dec[i]==0)i++;
        if(i==N)printf("0");
        else {while(i<N)printf("%d",dec[i++]);}
        printf("\n");
    }
}