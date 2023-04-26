#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char s[21];
    int num;
}strin;

int cmp(const void* a, const void* b)
{
    strin m = *(strin*)a, n = *(strin*)b;
    if(m.num != n.num)
        return n.num - m.num;
    return strcmp(n.s, m.s);
}

int main()
{
    int T, i, n, j;
    int t, k;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d", &n);
        strin str[n];
        for(j=0; j<n; j++)
        {
            str[j].num = 1;
            scanf("%s", &str[j].s);
            int len = strlen(str[j].s);
            for(t=1; t<len; t++)
            {
                for(k=t-1; k>=-1; k--)
                {
                    if(k == -1)
                    {
                        str[j].num++;
                        break;
                    }
                    if(str[j].s[t] == str[j].s[k])
                        break;
                }
            }
        }

        qsort(str, n, sizeof(str[0]), cmp);
        printf("case #%d:\n", i);
        for(j=0; j<n; j++)
            printf("%s\n", str[j].s);
    }

    return 0;
}
