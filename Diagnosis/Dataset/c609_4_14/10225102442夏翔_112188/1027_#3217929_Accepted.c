#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[12];
    long long score;
}Student;
int cmp1(const void *a, const void *b){
    Student x1=*(Student*)a, x2=*(Student*)b;
    if(x1.score>x2.score) return -1;
    else if(x1.score<x2.score) return 1;
    else return strcmp(x1.s,x2.s);
}
int main(){
    int T, N, M, G, num, ret, sco;
    scanf("%d", &T);
    Student *students;
    long long *scores;
    for(int k=0; k<T; k++){
        scanf("%d %d %d", &N, &M, &G);
        students = (Student*)malloc(sizeof(Student)*N);
        scores = (long long*)malloc(sizeof(long long)*M);
        for(int i=0; i<M; i++) scanf("%lld", &scores[i]);
        for(int i=0; i<N; i++){
            scanf("%s", students[i].s);
            scanf("%d", &num);
            students[i].score = 0;
            for(int j=0; j<num; j++){
                scanf("%d", &sco);
                students[i].score += scores[sco-1];
            }
        }
        qsort(students, N, sizeof(students[1]), cmp1);
        printf("case #%d:\n", k);
        ret = 0;
        for(int i=0; i<N; i++){
            if(students[i].score<G){
                ret = i;
                break;
            }
        }
        printf("%d\n", ret);
        for(int i=0; i<ret; i++) printf("%s %lld\n", students[i].s, students[i].score);
        free(students);
        free(scores);
    }



    return 0;
}