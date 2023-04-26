#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    while(scanf("%d",&n)&&n!=0)
    {
        long long int digit=n*log10(n);
        int left=pow(10.0,n*log10(n)-digit);
        printf("%d\n",left);
    }
    return 0;
}