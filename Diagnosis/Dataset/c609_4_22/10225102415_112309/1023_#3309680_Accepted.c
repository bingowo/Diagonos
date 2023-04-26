# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen 
// 1    2   3    4     5     6    7       8    9
// yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu, uayet
// 10   11   12   13   14      15    16   17     18     19

typedef struct {
	int d;
	int m;
	int y;
} DATE;

int cmp(const void *a, const void *b) {
	DATE *n1 = (DATE *)a, *n2 = (DATE *)b;
	if (n1->y != n2->y) return (n1->y) - (n2->y);
	else if (n1->m != n2->m) return (n1->m) - (n2->m);
	else return (n1->d) - (n2->d);
}

int Maya2Common(char s[10]) {
	//printf(">%s\n", s); 
	if (strcmp(s, "pop") == 0) return 1;
	else if (strcmp(s, "no") == 0) return 2;
	else if (strcmp(s, "zip") == 0) return 3;
	else if (strcmp(s, "zotz") == 0) return 4;
	else if (strcmp(s, "tzec") == 0) return 5;
	else if (strcmp(s, "xul") == 0) return 6;
	else if (strcmp(s, "yoxkin") == 0) return 7;
	else if (strcmp(s, "mol") == 0) return 8;
	else if (strcmp(s, "chen") == 0) return 9;
	else if (strcmp(s, "yax") == 0) return 10;
	else if (strcmp(s, "zac") == 0) return 11;
	else if (strcmp(s, "ceh") == 0) return 12;
	else if (strcmp(s, "mac") == 0) return 13;
	else if (strcmp(s, "kankin") == 0) return 14;
	else if (strcmp(s, "muan") == 0) return 15;
	else if (strcmp(s, "pax") == 0) return 16;
	else if (strcmp(s, "koyab") == 0) return 17;
	else if (strcmp(s, "cumhu") == 0) return 18;
	else if (strcmp(s, "uayet") == 0) return 19;
	else {
		printf("error in Maya2Common()\n");
		return -1;
	}
}

int main() {
	char MayaMonth[][10] = {"pop", "no", "zip", "zotz", "tzec", "xul",
							"yoxkin", "mol", "chen" , "yax", "zac", "ceh",
							"mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);
		DATE *p = (DATE *)malloc((N+1)*sizeof(DATE));
		for (int j = 0; j < N; j++) {
			scanf("%d.", &((p+j)->d));
			char s[10];
			scanf("%s", s);
			(p+j) -> m = Maya2Common(s);
			scanf("%d", &((p+j)->y));
			//printf(">%d:%d %d %d\n",j , (p+j)->d, (p+j)->m, (p+j)->y);
		}
		printf("case #%d:\n", i);
		qsort(p, N, sizeof(DATE), cmp);
		for (int j = 0; j < N; j++) {
			printf("%d. %s %d\n", (p+j)->d, MayaMonth[((p+j)->m)-1], (p+j)->y);
			//printf("%d:%d %d %d\n",j , (p+j)->d, (p+j)->m, (p+j)->y);
		}
	}
	return 0;
} 