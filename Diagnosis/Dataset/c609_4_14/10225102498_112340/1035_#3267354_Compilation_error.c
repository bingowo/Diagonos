#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int insert(char* s, char c)
{
    int i, tmp, cnt = 0, j = 0;
    char t[strlen(s)+2];
    for(i=0; i<=strlen(s); i++)
    {
        for(j=0; j<i; j++)
            t[j] = s[j];
        t[j] = c;
        for(j=i+1; j<=strlen(s); j++)
            t[j] = s[j-1];
        t[j] = 0;
        if((tmp=count(t))>cnt)
            cnt = tmp;
    }

    return cnt;
}

void solve()
{
    char s[N+1];
    int r, t;
    scanf("%s", s);
    r = insert(s,'A');
    if((t=insert(s,'B'))>r)
        r = t;
    if((t=insert(s,'C'))>r)
        r = t;
    printf("%d\n", r);
}

int main()
{
    int i, t;
    scanf("%d\n", &t);
    for(i=0; i<t; i++)
        printf("case #%d:\n", i),solve();

    return 0;
}
