#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char id[12];
	int score;
} student;

int cmp(const void *a, const void *b) {
	student *A = (student *)a;
	student *B = (student *)b;
	if (A->score == B->score) {
		return strcmp(A->id, B->id);
	} else
		return B->score - A->score;
}

int main() {
	int T;
	scanf("%d", &T);
	int o = 0;
	while (T--) {
		int N, M, G;
		int count = 0;
		scanf("%d %d %d", &N, &M, &G);
		student A[N];
		for (int i = 0; i < N; i++) {
			A[i].score = 0;
		}
		int w[M];
		for (int i = 0; i < M; i++) {
			scanf("%d", &w[i]);
		}
		for (int i = 0; i < N; i++) {
			int s;
			scanf("%s %d", A[i].id, &s);
			for (int j = 0; j < s; j++) {
				int k;
				scanf("%d", &k);
				A[i].score = A[i].score + w[k - 1];
			}
			if (A[i].score >= G)
				count++;
		}
		qsort(A, N, sizeof(A[0]), cmp);
		printf("case #%d:\n%d\n", o++, count);
		for (int i = 0; i < count; i++)
			printf("%s %d\n", A[i].id, A[i].score);
	}



}