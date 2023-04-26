#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu{
    char num[11];
    int fen;
};

int cmp(const void *a,const void *b);

int main()
{
    int T,N,M,G,i,j,k;
    scanf("%d",&T);
    for(i = 0;i < T;i++){
        printf("case #%d:\n",i);
        scanf("%d %d %d ",&N,&M,&G);
        int score[M];
        for(j = 0;j < M;j++){
            scanf("%d",&score[j]);
        }
        struct stu dent[N];
        for(j = 0;j < N;j++){
            dent[j].fen=0;
        }
        for(j = 0;j < N;j++){
            scanf("%s",dent[j].num);
            int shu,f;
            scanf("%d",&shu);
            for(k = 0;k < shu;k++){
                scanf("%d",&f);
                dent[j].fen+=score[f-1];
            }
        }
        int count = 0;
        qsort(dent,N,sizeof(struct stu),cmp);
        for(k = 0;k < N;k++){
            if(dent[k].fen >=G){
                count++;
            }
        }
        printf("%d\n",count);
        for(k = 0;k < N;k++){
            if(dent[k].fen >=G){
                printf("%s %d\n",dent[k].num,dent[k].fen);
            }
        }
    }

    return 0;
}

int cmp(const void *a,const void *b)
{
    struct stu x,y;
    x = *((struct stu*) a);
    y = *((struct stu*) b);
    if(x.fen != y.fen){
        return y.fen - x.fen;
    }
    else
        return strcmp(x.num,y.num);
}
