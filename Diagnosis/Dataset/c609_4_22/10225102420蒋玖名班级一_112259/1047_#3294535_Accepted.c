#include <stdio.h>
#include <stdlib.h>
#define N 95
void mul(int *result,int a)
{
    int i,carry=0;
    for(i=0;i<N;i++)
    {
        int t=result[i]*a+carry;
        result[i]=t%10;
        carry=t/10;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int a,n;
        int result[95]={1};
        scanf("%d%d",&a,&n);
        for(int j=0;j<n;j++)
            mul(result,a);
        printf("case #%d:\n",i);
        int flag=0;
        for(int j=N-1;j>=0;j--)
        {
            if(flag==0&&result[j]==0) continue;
            if(flag==1) printf("%d",result[j]);
            if(flag==0&&result[j]!=0)
            {
                flag=1;
                printf("%d",result[j]);

            }

        }
        printf("\n");

    }
    return 0;
}
