
#include <stdio.h>
#include <stdlib.h>
#define len 150000

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int a,n,N;
        scanf("%d %d %d",&a,&n,&N);
        int num[len]={0};
        num[len-1]=1;
        int j,h;
        for (j=0;j<n;j++)
        {
            for (h=len-1;h>=0;h--)
                num[h]*=a;
            for (h=len-1;h>=0;h--)
                if (num[h]>=10)
                {
                    num[h-1]+=num[h]/10;
                    num[h]=num[h]%10;
                }
        }
        int k;
        for (j=len-N,k=0;k<N;j++,k++)
            printf("%d",num[j]);
        printf("\n");
    }
    return 0;
}
