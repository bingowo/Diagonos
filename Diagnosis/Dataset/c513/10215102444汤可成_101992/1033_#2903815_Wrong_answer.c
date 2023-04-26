#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int val;
    int y;
    int d;
    char m[10];
}Maya;

int month(char* s)
{
    static char* month[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    int i = 0;
    for(i = 0; ;i++)
    {
        if(strcmp(s,month[i])==0) return i;
    }
}

int cmp(const void* pa, const void* pb)
{
    return ((Maya*)pa)->val - ((Maya*)pb)->val;
}

int main()
{
    int T = 0;
    int i = 0;
    scanf("%d", &T);
    for(i = 0; i<T; i++)
    {
        Maya s[10001];
        int n = 0;
        printf("case #%d:", i);
        scanf("%d", &n);
        int j = 0;
        for(j = 0; j<n; j++)
        {
            scanf("%d.%s %d", &s[j].d, &s[j].m, &s[j].y);
            s[j].val = s[j].y*1000+s[j].d+month(s[j].m)*20;
        }
        qsort(s, n, sizeof(s[0]), cmp);
        for(j = 0; j<n; j++)
        {
            printf("%d.%s %d\n",s[j].d, s[j].m, s[j].y);
        }
    }
    return 0;
}
