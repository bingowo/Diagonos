#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int compar(const void *p,const void *q)
{
    return *(int*)p-*(int*)q;
}
int main()
{
    int T,i,j,k,n,m,L,U,a[1002],dp[1002]={0},newp[1000000]={-1},dpnewp[1000000]={0},num;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d",&n,&m);
        num=1;                      //newp里的有效个数为num-1
        for(j=1;j<n+1;j++)
        {
            scanf("%d",&a[j]);
            dp[j]=dp[j-1]+a[j];
        }
        for(j=1;j<n+1;j++)
        {
            for(k=1;k<j;k++)
            {
                newp[num++]=dp[j]-dp[k];
            }
        }
        qsort(newp,num,sizeof(int),compar);
        for(j=1;j<num+1;j++)
        {
            dpnewp[j]=dp[j-1]+newp[j];
        }
        printf("case #%d:",i);
        while(m--)
        {
            scanf("%d%d",&L,&U);
            printf("%d",dpnewp[U]-dpnewp[L]);
        }
    }
    return 0;
}
