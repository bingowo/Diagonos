#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int T,i;
    unsigned long long n;
    unsigned long long num[10];
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%llu", &n);
        int j = 0;
        while(n >= 2333)
        {
            num[j] = n%2333;
            n /= 2333;
            j++;
        }
        //j--;
        for(int t=j; t>=0; t--)
            printf("%llu ", num[t]);
        printf("\n");
    }

    return 0;
}
