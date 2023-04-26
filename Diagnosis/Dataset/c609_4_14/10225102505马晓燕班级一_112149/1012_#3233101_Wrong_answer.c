#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0;t<T;t++)
    {
        long double  ans = 0;
        char c[52] = {'0'};
        scanf("%s",c);
        int i=strlen(c) - 1;

        while( i > 1)
        {
            ans = (ans + (c[i] - '0'))/8;
            i--;
        }
        printf("case #%d:\n",t);
        printf("%Lf",ans);
    }
    return 0;
}
