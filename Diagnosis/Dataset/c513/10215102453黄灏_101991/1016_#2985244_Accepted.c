#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,r,i = 0,m,k;
    char s[60];
    char table[]="0123456789ABCDEFGHIJK";
    scanf("%d %d",&n,&r);
    if(n == 0)
        printf("0");
    else
    {
        while(n)
        {
            m = n % r;
            n = n / r;
            if( m < 0) {
                n++;
                m = m - r;
            }
            s[i++] = table[m];
        }
        for(k= i - 1;k >= 0;k --)
            printf("%c",s[k]);
    }
    return 0;
}
