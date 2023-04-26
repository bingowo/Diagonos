#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    char *p1 = *((char **)a), *p2 = *((char **)b);
    int i = 0;
    while (*(p1 + i) != '@')
        i++;                    //查找字符@的位置
    char *domain1 = p1 + i + 1;       //domain1指向第一个邮件地址的主机域名
    i = 0;
    while (*(p2 + i) != '@')
        i++;
    char *domain2 = p2 + i + 1;       //domain2指向第二个邮件地址的主机域名
    if (strcmp(domain1, domain2) == 0)
        return strcmp(p2, p1);
    else
        return strcmp(domain1, domain2);
}

int main()
{
    int n, len;
    scanf("%d", &n);
    char **email = (char **)malloc(n * sizeof(char *)); //动态分配指针数组空间
    char s[1000010], *p;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        len = strlen(s);
        p = (char *)malloc(len + 1); //动态分配邮件地址存储空间
        strcpy(p, s);
        *(email + i) = p;
    }
    qsort(email, n, sizeof(char *), cmp);
    for (int i = 0; i < n; i++)
        printf("%s\n", email[i]);

    for (int i = 0; i < n; i++)
    {
        p = email[i];
        free(p);
    }
    free(email);
    return 0;
}
