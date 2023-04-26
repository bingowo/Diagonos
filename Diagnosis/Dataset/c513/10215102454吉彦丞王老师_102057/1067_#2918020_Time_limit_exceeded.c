#include<stdio.h>
long long int T(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1||n==2)
    {
        return 1;
    }
    else
    {
        return T(n-3)+T(n-2)+T(n-1);
    }
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",T(n));
    }
    return 0;
}