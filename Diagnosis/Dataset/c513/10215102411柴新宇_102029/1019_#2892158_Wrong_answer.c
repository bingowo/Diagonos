#include <stdio.h>
#include <math.h>


struct team {
	int score;
	int win;
	int lose;
	int number;
} T[100];

int cmp(const void *a, const void *b) {
	struct team c = *((struct team *)a);
	struct team d = *((struct team *)b);
	if (c.score == d.score) {
		if (c.win == d.win) {
			if (c.lose == d.lose)
				return c.number - d.number;
			return c.lose - d.lose;
		}
		return c.win < d.win;
	}
	return c.score < d.score;

}




int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) ) {
		if (n == 0 && m == 0)
			break;

		for (int i = 1; i < n + 1; i++) {
			T[i].number = i;
			T[i].score = 0;
			T[i].win = 0;
			T[i].lose = 0;
		}
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			{
				if (c == 1) {
					T[a].score += 3;
					T[a].win++;
					T[b].score--;
					T[b].lose++;

				} else if (c == -1) {
					T[b].score += 3;
					T[b].win++;
					T[a].score--;
					T[a].lose++;
				} else {
					T[a].score++;
					T[b].score++;
				}

			}

			qsort(T + 1, n, sizeof(T[0]), cmp);
		}
		for (int i = 1; i < n + 1; i++) {
			printf("%d ", T[i].number);
		}
		printf("\n");
	}


	return 0;
}