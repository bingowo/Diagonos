#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
	char *n1 = (char *)a, *n2 = (char *)b;
	return strcmp(n1, n2);
}

int main() {
	int T;
	scanf("%d", &T);
	char c;
	c = getchar();
	for (int i = 0; i < T; i++) {
		char line[500];
		gets(line);
		int len = strlen(line);
		for (int j = 0; j < len; j++) {
			if (line[j] == ',' || line[j] == '.' || line[j] == '!' || line[j] == '?') line[j] = ' ';
		}
		line[len] = ' ';
		line[++len] = '\0';
		char words[500][100];
		int m = 0, n = 0;
		for (int l = 0; l < len; l++) {
			if (line[l] != ' ') {
				words[m][n] = line[l];
				n++;
			} else if (line[l] == ' ' && line[l-1] != ' ' && line[l+1] != '\0') {
				words[m][n] = '\0';
				m++;
				n = 0;
			} else if (line[l+1] == '\0') {
				words[m][n] = '\0';
				m++;
			}
		}
		qsort(words, m, sizeof(words[0]), cmp);
		
		printf("case #%d:\n", i);
		for(int o = 0; o < m; o++) {
			if (strcmp(words[o], words[o-1]) != 0) printf("%s ", words[o]);
		}
		printf("\n");
	}
	return 0;
}