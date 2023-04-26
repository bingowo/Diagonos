#include <stdio.h>

int map[128];

int iselegant(char s[])
{
    int stack[101] = {}; int m = 0;
    for (int i=0;s[i];i++)
    {
        if (map[s[i]]<4)
        {
            stack[m++] = map[s[i]];
            if (m>1)
            {
                if (stack[m-1]==1&&stack[m-2]!=2) return 0;
                if (stack[m-1]==2&&stack[m-2]!=3) return 0;
                if (stack[m-1]==3&&stack[m-2]!=1) return 0;
            }
        }
        else if ((stack[--m]+map[s[i]]!=7)) return 0;
    }
    return 1;
}

int main()
{
    int T; scanf("%d ",&T);
    map['('] = 1, map['['] = 2, map['{'] = 3;
    map[')'] = 6, map[']'] = 5, map['}'] = 4;
    while (T--)
    {
        char s[101] = {};
        gets(s);
        if (iselegant(s)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}