#include<stdio.h>

#define N 100

void mul(int *res,int a);
int main()
{
    int t,a,n;
    int i,j;
    scanf("%d",&t);

    for (i=0;i<t;i++)
    {
        scanf("%d %d",&a,&n);

        int res[N]={1,0};
        for (j=0;j<n;j++)
        {
            mul(res,a);
        }

        printf("case #%d:\n",i);

        for (j=N-1;j>=0;j++)
        {
            if (res[j] != 0)
            {
                printf("%d",res[j]);
            }
        }
        putchar('\n');
    }
    return 0;
}

void mul(int *res,int a)
{
    int i;
    int c=0;
    
    for (i=0;i<N;i++)
    {
        int t=res[i]*a+c;
        res[i]=t%10;
        c=t/10;
    }
    
    return;
}