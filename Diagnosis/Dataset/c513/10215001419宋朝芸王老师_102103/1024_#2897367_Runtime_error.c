#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char num[11];
    int right[10];
    int score;
    int numRight;
    int pass;
} STUDENTS;

int cmp(const void *a, const void *b){
    STUDENTS *A = (STUDENTS*)a, *B = (STUDENTS*)b;
    if(A->score > B->score ) return -1;
    if(A->score < B->score ) return 1;

    for(int i = 10; i > -1; i--){
        if(A->num[i] > B->num[i]) return 1;
        if(A->num[i] < B->num[i]) return -1;
    }
    return 0;
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        int N,M,G;  //N for numOfStudents,M for numOfQuestions
        scanf("%d%d%d",&N,&M,&G);   //G for basic line

        STUDENTS stu[500];
        int qusVal[10];
        int pass = 0;

        for(int i = 1; i < M; i++){     //Quiz set
            scanf("%d",&qusVal[i]);
        }

        for(int i = 0; i < N; i++){
            scanf("%s%d",stu[i].num,&stu[i].numRight);

            stu[i].score = 0;
            for(int j = 0; j < stu[i].numRight; j++){
                scanf("%d",&stu[i].right[j]);
                stu[i].score += qusVal[stu[i].right[j]];
            }

            if(stu[i].score >= G) pass++;
        }


        STUDENTS* p = stu;
        qsort(p,N,sizeof(STUDENTS),cmp);

        printf("case #%d:\n%d\n",R,pass);

        for(int i = 0; i < pass; i++){
            printf("%s %d\n",stu[i].num,stu[i].score);
        }

    }
    return 0;
}
