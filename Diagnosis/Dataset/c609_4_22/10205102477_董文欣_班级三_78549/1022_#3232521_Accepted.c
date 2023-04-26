#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmp(const void *a, const void *b) {
    char *p1, *p2, *host1, *host2;
    p1 = *((char **)a);
    p2 = *((char **)b);
    int i = 0;
    while (*(p1 + i) != '@') i++;
    host1 = p1 + i + 1;

    i = 0;
    while (*(p2 + i) != '@') i++;
    host2 = p2 + i + 1;

    if (strcmp(host1,host2) == 0) return strcmp(p2,p1);
    else return strcmp(host1,host2);
}

int main()
{
    int n;
    scanf("%d", &n);

    char **email;
    email = (char **)malloc(n * sizeof(char *));

    char s[1000001];
    char *p;
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int len = strlen(s);

        p = (char *)malloc(len + 1);
        strcpy(p, s);
        * (email + i) = p;
    }

    qsort(email, n, sizeof(char *), cmp);
    for (int i = 0; i < n; i++) printf("%s\n",email[i]);

    return 0;
}
