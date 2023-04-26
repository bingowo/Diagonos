#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stu {
    char s[11];
    int C, M, E, A;
};

int cmp1(const void *a, const void *b) {
    struct stu *aa = (struct stu *) a, *bb = (struct stu *) b;
    if (aa->C != bb->C)
        return bb->C - aa->C;
    return strcmp(aa->s, bb->s);
}

int cmp2(const void *a, const void *b) {
    struct stu *aa = (struct stu *) a, *bb = (struct stu *) b;
    if (aa->M != bb->M)
        return bb->M - aa->M;
    return strcmp(aa->s, bb->s);
}

int cmp3(const void *a, const void *b) {
    struct stu *aa = (struct stu *) a, *bb = (struct stu *) b;
    if (aa->E != bb->E)
        return bb->E - aa->E;
    return strcmp(aa->s, bb->s);
}

int cmp4(const void *a, const void *b) {
    struct stu *aa = (struct stu *) a, *bb = (struct stu *) b;
    if (aa->A != bb->A)
        return bb->A - aa->A;
    return strcmp(aa->s, bb->s);
}

struct stu ST[100];

int main() {
    int T;
    scanf("%d", &T);
    for (int j = 0; j < T; j++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s%d%d%d", ST[i].s, &ST[i].C, &ST[i].M, &ST[i].E);
            ST[i].A = (ST[i].C + ST[i].M + ST[i].E) / 3.0+0.5;
        }
        
        printf("case #%d:\n", j);
        int k;
        qsort(ST, n, sizeof(ST[0]), cmp4);
        printf("A:\n");
        
        k=0;
        while (1)
        {
            printf("%s\n",ST[k].s);
            if(k+1<n && ST[k+1].A==ST[k].A)
                k++;
            else
                break;
        }
        qsort(ST, n, sizeof(ST[0]), cmp1);
        printf("C:\n");
        k=0;
        while (1)
        {
            printf("%s\n",ST[k].s);
            if(k+1<n && ST[k+1].C==ST[k].C)
                k++;
            else
                break;
        }
        qsort(ST, n, sizeof(ST[0]), cmp2);
        printf("M:\n");
        k=0;
        while (1)
        {
            printf("%s\n",ST[k].s);
            if(k+1<n && ST[k+1].M==ST[k].M)
                k++;
            else
                break;
        }
        qsort(ST, n, sizeof(ST[0]), cmp3);
        printf("E:\n");
        k=0;
        while (1)
        {
            printf("%s\n",ST[k].s);
            if(k+1<n && ST[k+1].E==ST[k].E)
                k++;
            else
                break;
        }
        
    }
    return 0;
}
