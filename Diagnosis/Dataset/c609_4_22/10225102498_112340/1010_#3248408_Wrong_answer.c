#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int R, r, t;
    char s[1000000] = {0};
    scanf("%d%d",&t, &R);
    
    int i = 0, k = 0;
    while(t)
    {
        k = t%R;
        t /= R;
        if(k<0)
        {
            k -= R;
            t++;
        }
        if(k < 10)
            s[i++] = k + '0';
        if(k >= 10)
            s[i++] = k - 10 + 'A';

    }
    for(r=i-1; r>=0; r--)
        printf("%c", s[r]);

    return 0;
}
