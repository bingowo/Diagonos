#include <stdio.h>
#include <math.h>


typedef struct Team {
	int num;
	int wins;
	int lose;
	int score;
} T;

//初始化结构体模板
T *newTeams(int n) {
	T *t = (T *)malloc(sizeof(T) * (n + 5));
	for (int i = 1; i <= n + 1; i++) {
		t[i].num = i;
		t[i].wins = 0;
		t[i].lose = 0;
		t[i].score = 0;
	}
	return t;
}

int cmp(const void *q1, const void *q2) {
	team *t1 = (team *) q1;
	team *t2 = (team *) q2;
	if (t1->point == t2->point) {
		if (t1->win == t2->win) {
			if (t1->lose == t2->lose) {
				return (t1->number - t2->number);
			}
			return (t1->lose - t2->lose); //
		}
		return (t2->win - t1->win);
	}
	return (t2->point - t1->point);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (n != 0 || m != 0) {
		T *t = newTeams(n);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (c > 0) {
				t[a].wins++;
				t[b].lose++;
				t[a].score += 3;
				t[b].score--;
			} else {
				if (c == 0) {
					t[a].score++;
					t[b].score++;
				} else {
					t[b].wins++;
					t[a].lose++;
					t[b].score += 3;
					t[a].score--;
				}
			}
		}
		qsort(t + 1, n, sizeof(T), cmp);
		for (int i = 1; i <= n; i++)
			printf("%d ", t[i].num);
		printf("\n");
		scanf("%d%d", &n, &m);
	}
	return 0;
}
