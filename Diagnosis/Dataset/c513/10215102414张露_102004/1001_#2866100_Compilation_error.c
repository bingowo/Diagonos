#include<stdio.h>
int main()
{
    int N,R,k;
    scanf("%d%d",&N,&R);
    if (N<0)
    {
        N=-N;
        printf("-");
    }
    if (N==0)
       {
           printf("0\n");continue;
       }
    int ans[32];
    int i=0;
    do
    {
        ans[i]=N%R;
        i=i+1;
        N=N/R;
    }
    while(N);
    for(k=i-1;k>=0;k--)
    {
        if(ans[i]>=10)
        {
            printf("%c",'A'+ans[i]-10);
        }
        else
            printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}