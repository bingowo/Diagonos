#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,tmp,m,len,s[10007],j;
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)break;
        n %= 10000;
        s[0] = n;
        len = 1;
        m = 0;
        for(k = 0; k < len; k++)
        {
            tmp = s[k] + m;
            s[k] = tmp%10;
            m = tmp/10;
        }
        while(m)
        {
            s[len] = m%10;
            m /= 10;
            len++;
        }
        for(j = 2; j <= n; j++)
            for(k = 0; k < len; k++)s[k] = s[k]*n%10000;
        for(k = 0; k < len; k++)
        {
            tmp = s[k] + m;
            s[k] = tmp%10;
            m = tmp/10;
        }
        while(m)
        {
            s[len] = m%10;
            m /= 10;
            len++;
        }
        printf("%d\n",s[len-1]);
    }
    return 0;
}