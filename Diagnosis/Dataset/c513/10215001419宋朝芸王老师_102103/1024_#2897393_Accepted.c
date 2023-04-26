#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char num[12];
    int score;
} STUDENTS;

int cmp(const void *a, const void *b){
    STUDENTS *A = (STUDENTS*)a, *B = (STUDENTS*)b;
    if(A->score > B->score ) return -1;
    if(A->score < B->score ) return 1;

    for(int i = 0; i < 11; i++){
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

        //STUDENTS* stu = (STUDENTS*)malloc(N*sizeof(STUDENTS));
        STUDENTS stu[500];
        int qusVal[11];
        int pass = 0;
        int numRight;
        int tag;

        for(int i = 1; i < M+1; i++){     //Quiz set
            scanf("%d",&qusVal[i]);
        }

        for(int i = 0; i < N; i++){
            scanf("%s%d",stu[i].num,&numRight);

            stu[i].score = 0;
            for(int j = 0; j < numRight; j++){
                scanf("%d",&tag);
                stu[i].score += qusVal[tag];
            }

            if(stu[i].score >= G) pass++;
        }


        STUDENTS* p = stu;
        qsort(p,N,sizeof(STUDENTS),cmp);

        printf("case #%d:\n%d\n",R,pass);

        for(int i = 0; i < pass; i++){
            printf("%s %d\n",stu[i].num,stu[i].score);
        }

        //free(stu);

    }
    return 0;
}
