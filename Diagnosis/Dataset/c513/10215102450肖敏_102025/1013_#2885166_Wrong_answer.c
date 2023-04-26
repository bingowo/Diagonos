#include <stdio.h>

int main()
{
    char s[30];
    int i,j,n = 0,m = 0,p = 1;
    scanf("%s",s);
    for(i = 0;s[i] != '\0';i ++)
    {
        if(s[i] == '.')
            break;
    }
    for (j = 0; s[j] != '\0'; j++)
    {
        if(s[j] == '2')
            s[j] = -1;
        else
            s[j] = s[j] - '0';
        if (j < i)
            n = n * 3 + s[j];
        if (j > i)
        {
            m = m * 3 + s[j];
            p *= 3;
        }
    }
    if(m < 0 && n > 0)
    {
        m = p + m;
        n -= 1;
    }
    else if(n < 0)
    {
        n += 1;
        m = p - m;
    }
    if( n && m && p)
        printf("%d %d %d",n,m,p);
    else if( n == 0 && m == 0 & p == 0)
        printf("%d",n);
    else if(!n)
        printf("%d %d",m,p);
    else
        printf("%d",n);
    return 0;
}
