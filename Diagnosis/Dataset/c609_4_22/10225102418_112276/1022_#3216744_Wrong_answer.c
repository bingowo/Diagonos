#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Email
{
    char *user;
    char *domain;
} Email;

int cmp(const void *ap, const void *bp)
{
    Email a = *(Email *)ap;
    Email b = *(Email *)bp;
    int flag1 = strcmp(a.domain, b.domain);
    if (!flag1)
    {
        int flag2 = strcmp(a.user, b.user);
        if (flag2 <= 0)
            return 0;
        else
            return 1;
    }
    if (flag1 > 0)
        return 0;
    else
        return 1;
}

int main()
{
    int cnt = 0;
    int n;
    scanf("%d", &n);
    getchar();
    Email *elist = (Email *)malloc(sizeof(Email) * (n + 1));
    char *str = (char *)malloc(sizeof(char) * 1000001);
    for (int i = 0; i < n; i++)
    {
        char ch;
        elist[i].user = str + cnt;
        while ((ch = getchar()) != '@')
        {
            str[cnt++] = ch;
        }
        str[cnt++] = '\0';
        elist[i].domain = str + cnt;
        while ((ch = getchar()) != '\n')
        {
            str[cnt++] = ch;
        }
        str[cnt++] = '\0';
    }
    qsort(elist, n, sizeof(Email), cmp);
    for (int i = 0; i < n; ++i)
    {
        printf("%s@%s", elist[i].user, elist[i].domain);
    }
    free(elist);
    free(str);
    return 0;
}