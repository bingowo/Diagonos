#include<stdio.h>
void trans(long long int num)
{   if(num>0)
    {trans(num/2333);
    printf("%lld ",num%2333);}
}
int main()
{
    long long int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   int num;
        scanf("%lld",&num);
        trans(num);
        printf("\n");
    }
    return 0;
}