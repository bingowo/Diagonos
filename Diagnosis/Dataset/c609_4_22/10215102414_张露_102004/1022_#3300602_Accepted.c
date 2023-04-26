#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mail 
{
    char* name;
    char* realm;
};

int qcmp(const void* q1, const void* q2)
{
    struct mail* p1 = (struct mail*)q1;
    struct mail* p2 = (struct mail*)q2;
    int judge = strcmp(p1->realm, p2->realm);
    if (judge == 0) {
        return strcmp(p2->name, p1->name);
    }
    return judge;
}

char all[10000000] = { 0 };

int main()
{
    int total;
    scanf("%d", &total);
    getchar();
    struct mail* M = (struct mail*)malloc(total * sizeof(struct mail));
    int len = 0;

    for (int i = 0; i < total; i++) {
        M[i].name = all + len;
        char c = getchar();
        while (c != EOF && c != '\n') {
            if (c == EOF || c == '\n') {
                all[len++] = '\0';
                continue;
            }
            if (c == '@') {
                all[len++] = '\0';
                M[i].realm = (all + len);
                c = getchar();
                continue;
            }
            all[len++] = c;
            c = getchar();
        }
        all[len++] = 0;
    }

    qsort(M, total, sizeof(struct mail), qcmp);
    for (int i = 0; i < total; i++) {
        printf("%s@%s\n", M[i].name, M[i].realm);
    }

    free(M);
    return 0;
}
