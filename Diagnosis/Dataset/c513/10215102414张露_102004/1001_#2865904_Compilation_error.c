#include<stdio.h>
int main()
{
    int N,R,i;
    scanf("%d%d",&N&R);
    if (N<0)
    {
        N=-N;
        printf("-");
    }
    int ans[32];table[36]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    do
    {
        ans[i]=N%R;
        i=i+1;
        N=N/R;
    }
    while(N);
    for(;i>0;i--)
        printf("%d",table[ans]);
    printf("\n");
    return 0;
    
}