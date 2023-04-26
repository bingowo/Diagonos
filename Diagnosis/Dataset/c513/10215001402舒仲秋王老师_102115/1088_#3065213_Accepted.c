#include <stdio.h>
#include <stdlib.h>

unsigned long long combo(int m,int n)
{
    int a=m,b=n;
    if(m-n<n) b=m-n;
    int c=b;
    int i,flag=0;
    unsigned long long mul1=1;
    for(i=a;i>a-b;i--)
    {
        if(i==2*c)
        {
            mul1*=2;
            flag+=1;
            c--;
        }
        else mul1*=i;
    }
    for(i=1;i<=b-flag;i++) mul1/=i;
    return mul1;
}

int main()
{
    int k,N;
    scanf("%d",&N);
    for(k=0;k<N;k++)
    {
        printf("case #%d:\n",k);
        int m,n;
        scanf("%d %d",&m,&n);
        if(m==n||n==0)
        {
            printf("1\n");
            continue;
        }
        unsigned long long ret=combo(m,n);
        printf("%llu\n",ret);
    }
    return 0;
}
