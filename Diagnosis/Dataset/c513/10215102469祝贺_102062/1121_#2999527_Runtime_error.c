#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define inf 1005

long long f(long long a,long long b){
    if(a<b) return b-a;
    else return a-b;
}

int main(){

    int n,ans=0;scanf("%d",&n);
    int wei[n];
    for(int i=0;i<n;i++){
        scanf("%d",&wei[i]);
        ans+=wei[i];
    }
    int p[1050]={0},top=1;
    char s[ans+1];

    memset(s,'0',ans);
    for(int i=0;i<n;i++){
        int newp=top;
        for(int j=0;j<top;j++){
            if(wei[i]+p[j]>=0) s[wei[i]+p[j]-1]='1';
            if(-wei[i]+p[j]>=0) s[-wei[i]+p[j]-1]='1';

            p[newp++]=wei[i]+p[j];
            p[newp++]=-wei[i]+p[j];
        }
        top=newp;
    }
    s[ans]=0;
    printf("%s",s);
    return 0;
}
