#include <stdio.h>
#include <string.h>

char so[51], sd[155];

int main()
{
    int t, cas, len, i, j, k, tmp;
    scanf("%d\n", &cas);
    for (t = 0; t < cas; ++t)
    {
        gets(so);
        len = strlen(so);
        k = 0;
        memset(sd, '\0', sizeof sd);
        for (i = len - 1; i >= 2; --i)
        {
            int n = so[i] - '0';
            for (j = 0; j < k || n; ++j)
            {  
                tmp = 10 * n + (j < k ? sd[j] - '0' : 0);
                sd[j] = tmp / 8 + '0';
                n = tmp % 8;
            }
            k = j;
        }
        printf("case #%d:\n0.%s\n", t, sd);
    }
    return 0;
}
