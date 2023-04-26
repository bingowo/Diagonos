#include<stdio.h>
int main()
{
    for(int i=0;i<500;i++)
    {
        unsigned long long a,b;
        scanf("%llu%llu",&a,&b);
        printf("%llu\n",a-b);
    }
    return 0;
}