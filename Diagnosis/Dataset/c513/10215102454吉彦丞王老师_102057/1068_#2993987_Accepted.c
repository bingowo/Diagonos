#include<stdio.h>
long int num(int n,int m)
{
    if(n<m)
    {
        return 0;
    }
    else if(n==m)
    {
        return 1;
    }
    else
    {
        return 2*num(n-1,m)-num(n-m-1,m)+(1<<(n-m-1));
    }
}
int main()
{
    while(1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==-1&&b==-1)
        {
            break;
        }
        else
        {
            printf("%ld\n",num(a,b));
        }
    }
    return 0;
}