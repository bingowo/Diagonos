#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,R,n,i=0,neg=0;
    int ans[33];
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&n);
    for(int j=0;j<n;j++){
    scanf("%d %d",&N,&R);
    if(N<0){
        N*=(-1);
        neg=1;
    }
    do{
        ans[i++]=N%R;
        N=N/R;
    }while(N!=0);
    if(neg)printf('-');
    for(;i>=0;i--)
    printf("%c",table[ans[i]]);
    printf('\n');
    }
    return 0;
}