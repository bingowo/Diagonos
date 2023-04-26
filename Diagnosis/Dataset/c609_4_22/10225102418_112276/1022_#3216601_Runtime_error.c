#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Email
{
    char *user;
    char *domain;
} Email;

void EPrint(Email e)
{
    printf("%s@%s", e.user, e.domain);
}

bool cmp(Email a, Email b)
{
    int flag1 = strcmp(a.domain, b.domain);
    if (!flag1)
    {
        int flag2 = strcmp(a.user, b.user);
        if (flag2 <= 0)
            return false;
        else
            return true;
    }
    if (flag1 > 0)
        return false;
    else
        return true;
}

int main()
{
    int cnt = 0;
    int n;
    scanf("%d", &n);
    getchar();
    char tmp[1] = {'\0'};
    Email *es = (Email *)malloc(sizeof(Email) * (n + 1));
    char *str = (char *)malloc(sizeof(char) * 1000001);
    for (int i = 0; i < n; i++)
    {
        es[i + 1].user = tmp;
        es[i + 1].domain = tmp;
        char ch;
        es[i].user = str + cnt;
        while ((ch = getchar()) != '@')
            str[cnt++] = ch;
        str[cnt++] = '\0';
        es[i].domain = str + cnt;
        while ((ch = getchar()) != '\n')
            str[cnt++] = ch;
        str[cnt++] = '\0';
    }
    qsort(es, n, sizeof(Email), cmp);
    for (int i = 0; i < n; ++i)
    {
        EPrint(es[i]);
    }
    free(es);
    free(str);
    return 0;
}