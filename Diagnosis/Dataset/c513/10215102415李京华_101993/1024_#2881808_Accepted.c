#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char id[12];    //学号
	int sum;
}student;

int cmp(const void *_a, const void *_b){
	student a = *(student *)_a;
	student b = *(student *)_b;
	
	if (a.sum != b.sum)
		return b.sum - a.sum;
	return strcmp(a.id, b.id);
}

int main()
{
	int ncase, T, i, j, k, g;
	scanf("%d",&ncase);
	for (T = 0; T < ncase; T++) {
		int n, m;
		scanf("%d%d%d", &n, &m, &g);
		//n - 学生数； m - 题数； g - 分数线

		int M[m + 1];
		//各题分数
		for (i = 1; i < m + 1; i++){
			scanf("%d",&M[i]);
//			printf("here:%d\n",M[i]);
		}

		//输入学生
		student students[n];
		for (i = 0; i < n; i++){
			scanf("%s", students[i].id);
			students[i].sum = 0;

			int cnt = 0;
			scanf("%d", &cnt);
			int grade;

			for (j = 0; j < cnt; j++){
				scanf("%d", &grade);
				students[i].sum += M[grade];
			}

//			printf("%s:%d\n", students[i].id, students[i].sum);
		}
		
		qsort(students, n, sizeof(students[0]), cmp);

		i = 0;
		while(1){
//			printf("here:%d\n", students[i].sum);
			if (students[i].sum < g)
				break;
			else
				i++;
		}
		
		printf("case #%d:\n", T);
		printf("%d\n", i);
		for (j = 0; j < i; j++)
			printf("%s %d\n",students[j].id, students[j].sum);
	}
	return 0;
}