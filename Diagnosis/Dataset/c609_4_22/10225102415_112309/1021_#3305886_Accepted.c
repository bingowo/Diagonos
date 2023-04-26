#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char mod[27];

int myStrCmp(const char *n1, const char *n2) {
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int i = 0;
	for(int i; i < len1 && i < len2; i++) {
		//char a = n1[i]; char b = n2[i];
		char a = (n1[i] >= 'a' && n1[i] <= 'z') ? n1[i]-32 : n1[i];
		char b = (n2[i] >= 'a' && n2[i] <= 'z') ? n2[i]-32 : n2[i];
		//printf("a:%c b:%c;", a, b);
		int m = 0, n = 0;
		for (m; m < 27; m++) if (a == mod[m]) break;
		for (n; n < 27; n++) if (b == mod[n]) break;
		//printf("i-%d m:%d,n:%d;\n", i, m, n);
		if (m != n) return m - n;
	}
	if (i == len1) return len2 - len1;
	else return len1 - len2;
}

int cmp(const void *a, const void *b) {
	char *n1 = (char *)a; char *n2 = (char *)b;
	//printf("n1:%s n2:%s\n", n1, n2); 
	return myStrCmp(n1, n2);
}

int main() {
	char c;
	while (scanf("%s", mod) != EOF && (c = getchar()) == '\n') {
		//printf(">%s\n", mod); 
		int i = 0;
		char words[120][100] = {0};
		scanf("%s", words[i++]);
		while ((c = getchar()) != '\n') { scanf("%s", words[i++]); }
		
		qsort(words, i, sizeof(words[0]), cmp);
		
		//printf("*%d:", i);
		for (int j = 0; j < i; j++) printf("%s ", words[j]);
		printf("\n");
	}
	return 0; 
}