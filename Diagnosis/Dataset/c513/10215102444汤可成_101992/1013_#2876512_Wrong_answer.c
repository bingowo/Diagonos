#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int a, int b)
{
    if (b == 0)
        return a>0?a:-a;
    else
        return GCD(b, a%b);
}

int main()
{
    char num[31] = {0};
    long long int sum = 0;
    scanf("%s", num);
    int len = strlen(num);
    int i = 0;
    while(num[i] != '.')
    {
        int n = num[i] - '0';
        if(n == 2)
        {
            n = -1;
        }
        sum = sum * 3 + n;
        if(i == len-1)
        {
            break;
        }
        i++;
    }
    if(i == len-1) printf("%lld ", sum);
    else
    {
        i++;
        int m = len - i;
        int s = 0;
        while(num[i])
        {
            int n = num[i] - '0';
            if(n == 2)
            {
                n = -1;
            }
            s = s*3 +n;
            i++;
        }
        int j = 0;
        int p = 1;
        for(j = 0; j<m; j++)
        {
            p = p*3;
        }
        int g = GCD(s, p);
        if(sum>0 && s >0)
        {
            printf("%lld %d %d", sum, s/g, p/g);
        }
        else if(sum == 0)
        {
            printf("%d %d", s/g, p/g);
        }
        else if(sum > 0 && s < 0)
        {
            sum--;
            s = s/g;
            p = p/g;
            s = p + s;
            printf("%lld %d %d", sum, s, p);
        }
        else if(sum < 0 && s > 0)
        {
            sum++;
            s = s/g;
            p = p/g;
            s = p - s;
            printf("%lld %d %d", sum, s, p);
        }
        else
        {
            printf("%lld %d %d", sum, -s/g, p/g);
        }
    }
    return 0;
}
