#include<stdio.h>
#include<string.h>
#define N 1000
void adjust(int a[]){
    int idx=0;
    while(a[idx]!=-1&&idx<N)idx++;
    if(idx==N)return;
    a[idx]=0;
    int end1=idx-1,end2=N-1;
    for(;end1>=0;end1--,end2--){
        a[end2]=a[end1];
        a[end1]=0;
    }
}
void add(int a[],int c[]){
    for(int i=N-1;i>0;i--){
        a[i]+=c[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
}
void get(int a[],int b[]){
    char ch;int idx=0;
    while((ch=getchar())&&ch!=' '&&ch!='.'){
        a[idx]=ch-'0';idx++;
    }
    if(idx)a[idx]=-1;
    if(ch==' ')return;
    idx=1;
    while((ch=getchar())&&ch!=' '){
        b[idx]=ch-'0';idx++;
    }
}
int main(){
    int a[N]={0},b[N]={0},c[N]={0},d[N]={0};
    get(a,b);
    get(c,d);
    adjust(a),adjust(c);
    add(b,d);
    int n;
    scanf("%d",&n);
    if(b[n+1]>=5){
        b[n]+=1;
        for(int i=n;i>0;i--){
            b[i-1]+=b[i]/10;
            b[i]%=10;
        }
    }
    a[N-1]+=b[0];
    add(a,c);
    int flag=0;
    for(int i=0;i<N;i++){
        if(a[i]!=0){
            while(i<N)printf("%d",a[i++]);flag=1;}
    }
    if(flag==0)printf("0");
    putchar('.');
    for(int i=1;i<=n;i++){
        printf("%d",b[i]);
    }
}