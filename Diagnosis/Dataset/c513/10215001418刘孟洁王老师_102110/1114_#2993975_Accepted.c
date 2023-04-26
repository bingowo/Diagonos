#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int GCD(int m,int n)
{
    if(m%n == 0)return n;
    else if(n%m == 0)return m;
    if(m > n)m -= n;
    else if(n > m)n -= m;
    return GCD(m,n);
}

int main()
{
    int i,k,a = 0,b = 0,c = 0,a1,a2,d,d1,d2,e1,e2,m,n;
    char s[1007];
    int sign[1007],x[1007] = {0};
    scanf("%s",s);
    int len = strlen(s);
    k = 0;
    for(i = 0; i < len; i++)
    {
        if(isdigit(s[i])&&s[i-1] != '^')
           {
               if(s[i-1] == '+'||i == 0)sign[k] = 1;
               else if(s[i-1] == '-')sign[k] = -1;
               for(; isdigit(s[i]); i++){x[k] = x[k]*10 + s[i]-'0';}
               x[k] *= sign[k];
               if(s[i+1] == '^')a = x[k];
               else if(s[i] == 'x'&&s[i+1] != '^')b = x[k];
               else if(s[i] == '\0')c = x[k];
               k++;
               i--;
           }
        else if(s[i] == 'x'&&!isdigit(s[i-1]))
            {
                if(s[i-1] == '+'||i == 0)x[k] = 1;
                else if(s[i-1] == '-')x[k] = -1;
               if(s[i+1] == '^')a = x[k];
               else if(s[i] == 'x'&&s[i+1] != '^')b = x[k];
               else if(s[i] == '\0')c = x[k];
               k++;
            }
    }
    int delta = b*b - 4*a*c;
    if(delta < 0)printf("No Answer!");
    else
    {
        d1 = b - sqrt(delta);
        d2 = b + sqrt(delta);
        m = GCD(abs(d1),abs(2*a));
        n = GCD(abs(d2),abs(2*a));
        d1 /= m; e1 = (2*a)/m;
        d2 /= n; e2 = (2*a)/n;
        a1 = a/e1;a2 = a/e2;
        if(a1>a2)
        {
            d = a1;
            a1 = a2;
            a2 = d;
        }
        else if(a1 == a2)
        {
            if(d1/e1>d2/e2)
          {
            d = d1;
            d1 = d2;
            d2 = d;
           }
        }
        printf("%d %d %d %d\n",a1,d1,a2,d2);
    }
    return 0;
}
