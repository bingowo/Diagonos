#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,R,T,ans[100],x,i,flag;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&R);
        x=0;
        if(N>0)
            flag=0;
        else
        {
            N*=-1;
            flag=1;
        }
        while(N>=R)
        {
            ans[x++]=N%R;
            N=N/R;
        }
        ans[x]=N;
        if(flag)
            printf("-");
        for(i=x;i>-1;i--)
        {
            if(ans[i]<10)
                printf("%d",ans[i]);
            else
                printf("%c",'A'+ans[i]-10);
        }
        printf("\n");
    }
    return 0;
}
