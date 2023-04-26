#include<stdio.h>
#include<stdlib.h>
typedef struct{
    long long int id;
    int score;
}Student;

int compare(const void *p1, const void *p2){
    Student stu1 = *(Student*)p1, stu2 = *(Student*)p2;
    if (stu1.score == stu2.score){
        if (stu1.id >stu2.id) return 1;
        return -1;
    }
    return stu2.score - stu1.score; 
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; i++){
        int peo, pro, pass, cnt = 0;
        scanf("%d%d%d", &peo, &pro, &pass);
        
        int *scores;
        scores = (int*)malloc(sizeof(int) * pro);
        for (int j = 0; j != pro&&scanf("%d", &scores[j]); j++);
        
        Student *students = (Student*)malloc(sizeof(Student) * peo);
        for (int j = 0; j != peo; j++){
            scanf("%lld", &students[j].id);
            students[j].score = 0;

            int gabage;
            scanf("%d", &gabage);

            while(getchar() != '\n'){
                int grade = 0;
                scanf("%d", &grade);
                students[j].score += scores[grade-1];
            }
            if (students[j].score >= pass) cnt++;
        }
        free(scores);
        qsort(students, peo, sizeof(students[0]), compare);

        if (cnt == 0) printf("case #%d:\n0\n", i);
        else{
            printf("case #%d:\n%d\n", i, cnt);
            for (int j = 0; j != cnt; j++)
                 printf("%-011lld %d\n", students[j].id, students[j].score);
        }
        free(students);
    }
    return 0;
}