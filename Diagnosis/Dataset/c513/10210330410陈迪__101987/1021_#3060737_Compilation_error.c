#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

int split_words(char *buf, char **dst) {
    int n=0;
    char *p = strtok(buf, " ");
    while(p) {
        strcpy(*dst++,p);
        n++;
        p = strtok(NULL, " ");
    }
    return n;
}

char **allocate(int n, int m) {
    char **b = (char **)malloc(n * sizeof(char *));
    for(int i=0; i<n; i++) {
        b[i] = (char *)malloc(m * sizeof(char));
    }
    return b;
}

void freen(char **p, int n) {
    for(int i=0; i<n; i++)
        free(p[i]);
    free(p);
}

char mapping[256];
int prior[256];
int cmp(const void *a, const void *b) {
    const char *s1 = *(char **)a, *s2 = *(char **)b;
    while(*s1 && (prior[toupper(*s1] == prior[toupper[*s2]))
    {
        s1++;
        s2++;
    }
    return prior[toupper(*s1] - prior[toupper(*s2];
}

int main() {
    while(gets(mapping) != NULL) {
        prior[0] = -1;
        for(int i=0; i<26; i++) {
            prior[mapping[i]] = i;
        }
        char line[50000];
        gets(line);
        char **dst = allocate(101,101);
        int n = split_words(line,dst);
        qsort(dst, n, sizeof(char*), cmp);
        for(int i=0; i<n; ++i) {
            printf("%s",dst[i]);
            if(i!=n-1) printf(" ");
        }
        printf("\n");
        freen(dst,101);
    }
    return 0;
}
