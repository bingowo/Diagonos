#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool ascend = false;

int cmp(const void *a, const void *b) {
	int *x = a, *y = b;
	if(ascend) return *x - *y;
	else return *y - *x;
}

int main() {
    char method[256];
	gets(method);
	if(method[0] == 'A') ascend = true;
	int v[1000];
	int *p = v;
	int count = 0;
	while(scanf("%d", p++) != EOF) {
		count++;
	}
	qsort(v, count, sizeof(int), cmp);
    int a = 1, b = 0;
    for(; a < count; ++a) {
        if(v[a] != v[b]) {
            v[++b] = v[a];
        }
    }
    for(int i = 0; i <= b; ++i) {
        printf("%d", v[i]);
        if(i != b) printf(" ");
    }
    printf("\n");
    
    return 0;
}
