#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int number(char* a) {
    int sum = 0;
    int len = strlen(a);
    for (int i = 0; i < len; i++) {
        if (isdigit(a[i])) {
            sum *= 10;
            sum += a[i];
        }
    }
    if (sum || sum == 0) return sum;
    return -1;
}

int strnumcmp (const void* a, const void* b) {
    char *aa = (char *)a;
    char *bb = (char *)b;
    int numa = number(aa), numb = number(bb);
    if (numa == numb) return strcmp(aa,bb);
    else {
        if (numa > numb) return 1;
        else return -1;
    }
}

int main()
{
    char s[101][31];
    int n = 0;
    while (scanf("%s",s[n]) != EOF) {n++;}

    qsort(s, n, sizeof(s[0]), strnumcmp);

    for (int i = 0; i < n; i++) {
        printf("%s ", s[i]);
    }
	return 0;
}

