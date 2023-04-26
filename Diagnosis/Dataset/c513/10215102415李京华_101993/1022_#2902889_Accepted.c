#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *_a, const void *_b) {
    char *a = *((char **)_a);
    char *b = *((char **)_b);
    char *adomain, *bdomain;

    int i = 0;
    while (*(a + i) != '@')
        i++;
    adomain = a + i + 1;
    i = 0;
    while (*(b + i) != '@')
        i++;
    bdomain = b + i + 1;

    if (strcmp(adomain, bdomain) != 0)
        return strcmp(adomain, bdomain);
    return strcmp(b, a);
    
}

int main() {
    int n;
    scanf("%d", &n);
    char **email = (char **)malloc(n * sizeof(char *));

    char s[1000001], *tmp;
    int i;
    for (i = 0; i < n; i++) {
        scanf("%s", s);
        tmp = (char *)malloc(strlen(s) + 1);
        strcpy(tmp, s);
        *(email + i) = tmp;
    }

    qsort(email, n, sizeof(char *), cmp);

    for (i = 0; i < n; i++)
        printf("%s\n", email[i]);

    for (i =0; i < n; i++) {
        tmp = email[i];
        free(tmp);
    }
    free(email);

    return 0;
}