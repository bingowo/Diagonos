#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test{
	int num;
	int score;
	int win;
	int lose;
}A;

int cmp(const void* a, const void* b)
{
	int pa = ((A*)a)->score;
	int pb = ((A*)b)->score;
	int ha = ((A*)a)->num;
	int hb = ((A*)b)->num;
	int wa = ((A*)a)->win;
	int wb = ((A*)b)->win;
	int la = ((A*)a)->lose;
	int lb = ((A*)b)->lose;
	if (pa != pb) {
		return pb - pa;
	}
	else {
		if (wa != wb) {
			return wb - wa;
		}
		else {
			if (la != lb) {
				return la - lb;
			}
			else {
				return ha - hb;
			}
		}
	}

}


int main()
{
	int m,n,a,b,c;
	while (1) {
		scanf("%d %d", &m, &n);
		if ((m == 0) && (n == 0)) {
			break;
		}
		else {
			A ch[m];
            memset(ch,0,sizeof(ch[0])*m);
            for(int i = 0;i < m;i++){
                ch[i].num = i + 1;
            }
			for (int i = 0; i < n; i++) {
				scanf("%d %d %d", &a, &b, &c);
                if (c == 0) {
					ch[a - 1].score += 1;
					ch[b - 1].score += 1;
				}
				if (c == 1) {
					ch[a - 1].score += 3;
					ch[b - 1].score -= 1;
					ch[a - 1].win += 1;
					ch[b - 1].lose += 1;
				}
				if (c == -1) {
					ch[b - 1].score += 3;
					ch[a - 1].score -= 1;
					ch[b - 1].win += 1;
					ch[a - 1].lose += 1;
				}
			}
			qsort(ch, m, sizeof * ch, cmp);
			for (int j = 0; j < m; j++) {
				printf("%d%c", ch[j].num, j != m - 1 ? ' ' : '\n');
			}
		}
	}

	return 0;
}