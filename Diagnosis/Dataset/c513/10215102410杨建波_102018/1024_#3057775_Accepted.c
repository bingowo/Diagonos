#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stu{
    char a[12];
    int score;
} STU;

int cmp(const void*a,const void*b){
    STU p1,p2;
    p1 = *(STU*)a;
    p2 = *(STU*)b;
    if(p1.score == p2.score)return strcmp(p1.a, p2.a);
    else return p1.score>p2.score? -1:1;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        int N, M, G;
        scanf("%d %d %d", &N, &M, &G);
        int Mm[11] = {0}, a;
        for(int j = 1;j <= M; j++){
            scanf("%d",&a);
            Mm[j] = a;
        }
        STU *stud;
        stud = (STU*)malloc(N*sizeof(STU));
        for(int k = 0;N > k;k++){
            char s[12];
            int S, n, sum = 0;
            scanf("%s %d", s, &S);
            for(S;S > 0;S--){
                scanf("%d",&n);
                sum = sum + Mm[n];
            }
            strcpy(stud[k].a ,s);
            stud[k].score = sum;
        }
        qsort(stud, N, sizeof(STU), cmp);
        printf("case #%d:\n", i);
        int mem = 0;
        for(int k = 0;N > k;k++){
            if(stud[k].score >= G)mem++;
            else break;
        }
        printf("%d\n",mem);
        for(int k = 0;mem > k;k++){
            printf("%s %d\n",stud[k].a,stud[k].score);
        }
    free(stud);
    }
}