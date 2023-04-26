#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int ans[5][5];
        int a[4][4];
        int j,k;
        for(j=0;j<5;j++)
        {
            for(k=0;k<5;k++)
                ans[j][k]=1;
        }
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                scanf("%d",&a[j][k]);
            }
        }
        for(int q=0;q<3;q++)
        {
            for(int w=0;w<3;w++)
            {
                if(a[q][w]>0&&a[q][w]%2!=0)
                {

                         ans[q+1][w+1]=abs(ans[q+1][w+1]-1);
                          ans[q][w+1]=abs(ans[q][w+1]-1);
                           ans[q+1][w]=abs(ans[q+1][w]-1);
                            ans[q+2][w+1]=abs(ans[q+2][w+1]-1);
                             ans[q+1][w+2]=abs(ans[q+1][w+2]-1);
                }
            }
        }
        printf("case #%d:\n",i);
        for(j=1;j<4;j++)
        {
            for(k=1;k<4;k++)
            {
                printf("%d ",ans[j][k]);
            }
            printf("\n");
        }
    }
}
