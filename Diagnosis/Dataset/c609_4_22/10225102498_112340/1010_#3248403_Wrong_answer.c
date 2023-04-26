#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, R, r, t;
    char s[1000000] = {0};
    scanf("%d%d",&n, &R);
    r = -R;
    t = n;
    int m = 0, i = 0, k = 0;
    while(t)
    {
        k = t%R;
        t /= R;
        printf("k=%d\n", k);
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
    printf("%s", s);

    return 0;
}
