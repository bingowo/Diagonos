#include<stdio.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        long long int n;
        scanf("%lld\n",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",(1<<n));         
    }
    return 0;
}  