#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 105
#define SIZE 305

typedef struct {
	char domain[SIZE];
	char viraddr[SIZE];
	char site[SIZE];
}web;

int isHTTP(char s[]) {
	if (s[4] == 's') return 1;
	return 0;
}

void getDomainAndAddr(web b, char* Dest1, char* Dest2) {
	int cat = 0, idx = 0, j = 0;
	while (cat < 3) {
		if (b.site[idx] == '/')cat++;
		idx++;
	}
	for (int i = 0; i < idx; ++i) {
		Dest1[i] = b.site[i];
	}
	Dest1[idx] = 0;
	for (int i = idx; i < strlen(b.site); ++i) {
		Dest2[j++] = b.site[i];
	}
	Dest2[j] = 0;
}

int cmp(const void* a, const void* b) {
	web* wa = (web*)a;
	web* wb = (web*)b;
	if (strcmp(wa->domain, wb->domain))
		return strcmp(wa->domain, wb->domain);
	else return strcmp(wa->viraddr, wb->viraddr);
}

int main() {
	int web_num;
	web webarr[N]; int wn = 0;
	char input[SIZE] = {0};
	scanf("%d", &web_num);
	for (int i = 0; i < web_num; ++i) {
		scanf("%s", input);
		if (isHTTP(input))continue;
		strcpy(webarr[wn].site, input);
		getDomainAndAddr(webarr[wn], webarr[wn].domain, webarr[wn].viraddr);
		wn++;
		memset(input, 0, SIZE);
	}
	//printf("\n");
	qsort(webarr, wn, sizeof(webarr[0]), cmp);
	for (int i = 0; i < wn; ++i) {
		printf("%s %s\n", webarr[i].domain, webarr[i].viraddr);
	}
	return 0;
}