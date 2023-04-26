#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        long long n;
        scanf("%lld",&n);
        long long a[1111];
        long long s[1111];
        int i = 0, j = 0;
        for (i; n > 0; i++, n /= 2333)
        {
            a[i] = n % 2333;
        }
        i--;
        //printf("i=%d\n",i);
        for (i,j; i>=0; i--, j++)
        {
            s[j] = a[i];
        }
        j--;
        //printf("j=%d\n",j);
        for (int k = 0; k <= j; k++)
        {
            printf("%lld ",s[k]);
        }
        printf("\n");

    }
    return 0;
}
