#include <stdio.h>
#include <stdlib.h>
int trans(int *a)
{
    int i,res = 0;
    for(i = 0;i<8;i++)
    {
        res = res * 2+a[i];
    }
    return res;
}
int ans(int *a)
{
   int res,j;
   res = trans(a);
    //printf("%d ",res);
   for(j = 0;j<7;j++)
   {int i,t = a[0];
   for(i = 0;i<7;i++)
   {
       a[i] = a[i+1];
   }
   a[7] = t;
   //printf("%d ",trans(a));
   res = (trans(a)>res)?res:trans(a);
   }
   return res;
}
int main()
{
    int W,H,i,j,a[100][100];
    scanf("%d %d",&W,&H);
    for(i =0;i<H;i++)
    {
        for(j = 0;j<W;j++)
            scanf("%d",&a[i][j]);
    }
    for(i = 1;i<H-1;i++)
    {
        for(j = 1;j<W-1;j++)
        {
            int b[8],k = 0,m,n;
            for(m = i-1;m<=i+1;m++)
            {
                for(n = j-1;n<=j+1;n++)
                {//printf("%d ",a[m][n]);
                    if(m==i&&n==j);
                else if(a[m][n]>=a[i][j]) b[k++] = 1;
                else b[k++] = 0;}
            }
            int t;
            t = b[3];b[3] = b[4];b[4] = b[7];b[7] = t;
            t = b[5];b[5] = b[6];b[6] = t;
            //printf("%d %d %d %d %d %d %d %d\n",b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7]);
            printf("%d ",ans(b));
        }
        printf("\n");
    }
    return 0;
}
