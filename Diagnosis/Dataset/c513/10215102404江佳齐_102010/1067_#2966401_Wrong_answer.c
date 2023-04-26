#include <stdio.h>
#include <stdlib.h>
long long int f(int n)
{
    if(n==0) return 0;
    if(n==1||n==2) return 1;
    long long int one=0,two=1,three=1,sum;
    for(int i=3;i<n;i++)
    {
        sum=one+two+three;
        one=two;two=three;three=sum;
    }
    return sum;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        long long int result;
        scanf("%d",&n);
        result=f(n);
        printf("case #%d:\n",i);
        printf("%lld\n",result);
    }
    return 0;
}
