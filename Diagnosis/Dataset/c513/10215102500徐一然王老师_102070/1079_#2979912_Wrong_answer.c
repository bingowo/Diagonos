#include <stdio.h>
int main()
{
    int count,count1,n,m,L,U;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        int A[1001]={0};
        int B[1000000]={0};
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
        }
        int j=0;
        for(int i=1;i<=n;i++)
        {
            for(int p=0;p+i<=n;p++)
            {
                int flag=0;
                    for(int k=p;flag<i;k++)
                {
                    B[j]=B[j]+A[k];
                    flag++;
                }
                j++;
            }
        }
        printf("case #%d:\n",count1-count-1);
        for(int i=0;i<m;i++)
        {
            int sum=0;
            scanf("%d %d",&L,&U);
            for(int j=L-1;j<U;j++)
            {
                sum=sum+B[j];
            }
            printf("%d\n",&sum);

        }

    }
}

