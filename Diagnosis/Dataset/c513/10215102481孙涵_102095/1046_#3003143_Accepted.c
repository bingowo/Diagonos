#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void str_lower(char *p) {
    while(*p) {
        *p = tolower(*p);
        p++;
    }
}
int split_words(char *buf, char **dst) {
	int n = 0;
	char *p = strtok(buf, " ");
	while(p) {
		*dst = p;
        str_lower(*dst);
		n++;
		p = strtok(NULL, " ");
        dst++;
	}
	return n;
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    for(int i = 0; i < T; ++i) {
        char line[50000];
        gets(line);
        char **dst = (char **)malloc(1000 * sizeof(char *));
		int n = split_words(line, dst);
        int count = n;
        for(int i = 0; i < n; i++) {
            if( strcmp(dst[i], "the") == 0 ||
                strcmp(dst[i], "a") == 0   ||
                strcmp(dst[i], "an") == 0  ||
                strcmp(dst[i], "of") == 0  ||
                strcmp(dst[i], "for") == 0 ||
                strcmp(dst[i], "and") == 0)
                    count--;
        }
        printf("case #%d:\n%d\n", i, count);
    }
    
	return 0;
}