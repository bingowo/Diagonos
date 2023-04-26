#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *domain(char *addr)
{
    for (int i = 0; addr[i] != '@'; i++)
        return addr + i + 1;
}

int cmp(const void *a, const void *b)
{
    char *addr1 = *(char **)a;
    char *addr2 = *(char **)b;
    int delta = strcmp(domain(addr1), domain(addr2));
    if (delta)
        return delta;
    return -1 * strcmp(addr1, addr2);
}

int main()
{
    int n;
    scanf("%d", &n);
    // getchar();
    char **arr;
    for (int i = 0; i < n; ++i)
    {
        char *s = (char *)malloc(1000010 * sizeof(char));
        // gets(s); // getline(cin, s);
        scanf("%s", s);
        arr[i] = (char *)malloc((strlen(s) + 1) * sizeof(char));
        strcpy(arr[i], s);
        free(s);
    }
    qsort(arr, n, sizeof(arr[0]), cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }

    free(arr);
    return 0;
}