#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char data[11];
    char time[6];
    int size;
    char name[100];
};
struct file F[101];

int cmp1(const void *a, const void *b) {
    struct file *a1 = (struct file *) a, *b1 = (struct file *) b;
    return strcmp(a1->name, b1->name);
}

int cmp2(const void *a, const void *b) {
    struct file *a1 = (struct file *) a, *b1 = (struct file *) b;
    if (a1->size != b1->size)
        return a1->size - b1->size;
    else
        return strcmp(a1->name, b1->name);
}

int cmp3(const void *a, const void *b) {
    struct file *a1 = (struct file *) a, *b1 = (struct file *) b;
    if (strcmp(a1->data, b1->data) != 0)
        return strcmp(a1->data, b1->data);
    else if (strcmp(a1->time, b1->time) != 0)
        return strcmp(a1->time, b1->time);
    else
        return strcmp(a1->name, b1->name);
}


int main() {
    int n;
    scanf("%d", &n);
    while (n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%s%s%d%s", F[i].data, F[i].time, &F[i].size, F[i].name);
        }
        char s1[4], s2[5];
        scanf("%s%s", s1, s2);
        if (strcmp(s2, "/NAME") == 0) {
            qsort(F, n, sizeof(F[0]), cmp1);
        } else if (strcmp(s2, "/SIZE") == 0) {
            qsort(F, n, sizeof(F[0]), cmp2);
        } else {
            qsort(F, n, sizeof(F[0]), cmp3);
        }
        for(int j=0;j<n;j++)
        {
            printf("%s %s %016d %s\n",F[j].data,F[j].time,F[j].size,F[j].name);
        }
        printf("\n");
        scanf("%d", &n);
    }
    return 0;
}
