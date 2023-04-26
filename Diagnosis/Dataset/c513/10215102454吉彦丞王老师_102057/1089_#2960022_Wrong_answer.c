#include<stdio.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int a,b,n;
        scanf("%d%d%d",&a,&b,&n);
        int d[n+1];
        for(int j=0;j<n+1;j++)
        {
            d[j]=0;
        }
        d[0]=1;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                d[k]=d[k]*a;
            }
            for(int k=1;k<n+1;k++)
            {
                while(d[k-1]>=10)
                {
                    d[k]=d[k]+d[k-1]/10;
                    d[k-1]=d[k-1]%10;
                }
            }
        }
        printf("case #%d:\n",i);
        for(int j=n-1;j>=0;j--)
        {
            printf("%d",d[j]);
        }
        printf("\n");
    }
    return 0;
}