#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

int split_words(char *buf, char **dst) {
	int n = 0;
	char *p = strtok(buf, " ");
	while(p) {
		strcpy(*dst++, p);
		n++;
		p = strtok(NULL, " ");
	}
	return n;
}

char **allocate(int n, int m) {
	char **b = (char **)malloc(n * sizeof(char *));
	for(int i = 0; i < n; i++) {
		b[i] = (char *)malloc(m * sizeof(char));
	}
	return b;
}

void freen(char **p, int n) {
	for(int i = 0; i < n; i++)
		free(p[i]);
	free(p);
}

int p[256];
char alpha[256];
int cmp(const void *a, const void *b) {
	const char *s1 = *(char **)a, *s2 = *(char **)b;
	while(*s1 && (p[toupper(*s1)] == p[toupper(*s2)]))
    {
        s1++;
        s2++;
    }
    return p[toupper(*s1)] - p[toupper(*s2)];
}

int main() {
    while(gets(alpha) != NULL) {
        p[0] = -1;
		for(int i = 0; i < 26; i++) {
            p[alpha[i]] = i;
        }
        char line[50000];
        gets(line);
        char **a = allocate(101, 101);
		int n = split_words(line, a);
        qsort(a, n, sizeof(char*), cmp);
        for(int i = 0; i < n; ++i) {
            printf("%s", a[i]);
            if(i != n - 1) printf(" ");
        }
		printf("\n");
		freen(a, 101);
    }
    return 0;
}
