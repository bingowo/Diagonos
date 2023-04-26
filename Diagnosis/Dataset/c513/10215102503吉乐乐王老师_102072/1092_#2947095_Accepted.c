#include<stdio.h>
#include<string.h>
#define N 10000
void mult(int a[],int num){
    for(int i=N-1;i>0;i--)a[i]*=num;
    for(int i=N-1;i>0;i--){
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
}
int main(){
    char s[N];
    scanf("%s",s);
    int a[N]={0};a[N-1]=1;
    int n=strlen(s);
    if(n==1){printf("1");return 0;}
    for(int i=0;i<n;i++){
        if(i==0){
            if(s[i]==s[i+1])continue;
            else mult(a,2);
        }
        else if(i==n-1){
            if(s[i]==s[i-1])continue;
            else mult(a,2);
        }
        else{
            if(s[i]==s[i-1]&&s[i]==s[i+1])continue;
            else if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])mult(a,3);
            else mult(a,2);
        }
    }
    int idx=0;
    while(a[idx]==0)idx++;
    while(idx<N)printf("%d",a[idx++]);
}