#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cas,i,j,h,r,c,n,k,x,y,hang,lie,num,ans;
    int A[17][17];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        scanf("%d%d%d%d",&r,&c,&n,&k);
        for(j = 0; j <= r; j++)memset(A[j],0,sizeof(A[j]));
        for(j = 0; j < n; j++)
        {
            scanf("%d%d",&x,&y);
            A[x][y] = 1;
        }
        for(j = 1; j <= r; j++)
                for(h = 1; h <= c; h++)A[j][h]  = A[j][h-1] + A[j][h];
        if(n < k)printf("case #%d:\n0\n",i);
        //else if(n == k)printf("case #%d:\n1\n",i);
        else
        {
            for(j = 1,ans = 0; j <= r; j++)
                for(h = 1; h <= c; h++)
            {
                for(lie = 0; h+lie <= c; lie++)
                    for(hang = 0,num = 0; j+hang <= r; hang++)
                {
                    num += A[j+hang][h+lie] - A[j+hang][h-1];
                    if(num >= k)ans++;
                }
            }
            printf("case #%d:\n",i);
            printf("%d\n",ans);
        }
    }
    return 0;
}