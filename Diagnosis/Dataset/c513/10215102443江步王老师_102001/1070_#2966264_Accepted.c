#include<stdio.h>


void count(int n);

int main()
{
    int n;
    scanf("%d",&n);
    while (n>0)
    {
        count(n);
        scanf("%d",&n);
    }

    return 0;
}

void count (int n)
{
    if (n==1)
    {
        printf("2\n");
        
    }
    else if (n==2)
    {
        printf("4\n");
    }
    else 
    {
        int d00=1,d01=1,d10=1,d11=1;
        int i=3;
        
        while (i++ <= n)
        {
            int t1=d00,t2=d01,t3=d10,t4=d11;

            d00=t1+t2;
            d01=t3+t4;
            d10=t1;
            d11=t3+t4;
        }

        printf("%d\n",d00+d01+d10+d11);
    }

    return ;
}