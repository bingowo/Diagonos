#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long int a,b;
    int s[100];
    memset(s,0,sizeof(s));
    scanf("%lld %lld",&a,&b);
    if(a == 0)
    {
        printf("0");
    }
    else
    {
        int n = 0;
        while(a > 0)
        {
            s[n++] = a % 3;
            a /= 3;
        }
        for(int i = 0; i < n; i++)
        {
            if(s[i] + 1 >= 3)
            {
                s[i] -= 2;
                s[i+1]++;
            }
            else
            {
                s[i]++;
            }
        }
        if(s[n] != 0)
        {
            s[n]++;
            n++;
        }
        for(int i = 0; i < n; i++)
        {
            s[i]--;
            if(s[i] == -1)s[i] = 2;
        }
        int k = 0;
        b /= 3;
        while(b > 0)
        {
            k++;
            b /= 3;
        }
        if(k > n - 1)
        {
            printf("0.");
            for(int i = 0; i < n - k; i++)printf("0");
            for(int i = n - 1; i >= 0; i--)
            {
                printf("%d",s[i]);
            }
        }
        else
        {
            for(int i = n - 1; i >= k; i--)
            {
                printf("%d",s[i]);
            }
            if(k != 0)printf(".");
            for(int i = k - 1; i >= 0; i--)
            {
                printf("%d",s[i]);
            }
        }
    }
    return 0;
}
