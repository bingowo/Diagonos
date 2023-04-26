#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a, const void *b);

typedef struct{
    int ID[12];
    int sum;
}Student;

int main()
{
    int T,t;
    scanf("%d",&T);
    int j,k;
    int N,M,G,num,que;
    for(t = 0; t < t; t++){
      int cnt = 0;
      int score[11];
      Student stu[500];
      scanf("%d %d %d", &N, &M, &G);
      for(j = 0; j < M; j++){
        scanf("%d",&score[j]);
      }
      for(j = 0; j < N; j++){
        scanf("%s",&stu[j].ID);
        stu[j].sum = 0;
        scanf("%d",&num);
        for(k =  0; k < num; k++){
            scanf("%d", &que);
            stu[j].sum = stu[j].sum + score[que];
        }
        if(stu[j].sum >= G){
            cnt++;
        }
      }
      qsort(stu, N,sizeof(stu[0]),cmp);
      printf("case #%d:\n", t);
      printf("%d\n", cnt);
        for (j = 0; j < cnt; j++)
        {
            printf("%s %d\n", stu[j].ID, stu[j].sum);
        }
    }
    return 0;
}

int cmp(const void *a, const void *b){
    Student x = (*(Student*)a);
	Student y = (*(Student*)b);
	if(x.sum == y.sum) {
        return strcmp(x.ID, y.ID);
    } else {
        return y.sum - x.sum;
    }
}
