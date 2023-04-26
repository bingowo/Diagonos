#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void pow1(int a,int b)
{
    long long int sum=1;
    for(int i=0;i<b;i++) sum=sum*a;
    printf("%lld\n",sum);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        pow1(2,n);
    }
    return 0;
}
