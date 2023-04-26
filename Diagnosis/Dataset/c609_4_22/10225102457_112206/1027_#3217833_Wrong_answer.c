#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int cmp(const void *p1,const void *p2);
typedef struct{
    unsigned long long num;
    unsigned long long score;
}STUDENT;

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int i = 0; i < T; i++){
        int N,M,G;
        scanf("%d%d%d",&N,&M,&G);
        int T[M];
        for(int v = 0; v < M; v++){
            scanf("%d",&T[v]);
        }
        
        STUDENT data[N];
        for(int v = 0; v < N; v++){//read
            scanf("%llu",&data[v].num);
            data[v].score = 0;
            int s,st;
            scanf("%d",&s);
            for(int z = 0; z < s; z++){
                scanf("%d",&st);
                data[v].score += T[st-1];
            }
        }

        qsort(data,N,sizeof(STUDENT),cmp);

        for(int v = N-1; v >= 0; v++){
            if(data[v].score >= G) break;
            N--;
        }

        printf("case #%d:\n",i);
        if(N == 0){
            printf("0\n");
            continue;
        }
        printf("%d\n",N);
        for(int v = 0; v < N; v++){
            printf("%llu %llu\n",data[v].num,data[v].score);
        }
    }

    return 0;
}

int cmp(const void *p1,const void *p2)
{
    STUDENT a = *(STUDENT*)p1;
    STUDENT b = *(STUDENT*)p2;

    if(a.score != b.score) return b.score > a.score?1:a.score > b.score?-1:0;
    else return a.num > b.num?1:a.num < b.num?-1:0;
}