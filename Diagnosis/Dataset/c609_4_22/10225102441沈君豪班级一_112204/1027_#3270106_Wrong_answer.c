#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char s[12];      //学号
    int  score;         //得分

}hhh;

int cmp(const void*a,const void*b)
{
    hhh A=*(hhh*)a;
    hhh B=*(hhh*)b;
    if(A.score!=B.score){
        return B.score-A.score;
    }else{
        return strcmp(A.s,B.s);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N,M,G;          //学生人数  问题数 分数线
        scanf("%d %d %d",&N,&M,&G);
        int a[M+1];           //用一个数组给每一个题目赋分
        for(int j=1;j<M+1;j++){
            scanf("%d",&a[j]);
        }
        hhh* p=(hhh*)malloc(sizeof(hhh)*N);
        for(int j=0;j<N;j++){
            scanf("%s",p[j].s);
            int S;             //回答问题的正确数
            scanf("%d",&S);
            int x=0;             //分数
            int y;             //第几题
            for(int k=0;k<S;k++){
                scanf("%d",&y);
                x+=a[y];
            }
            p[j].score=x;
        }
        qsort(p,N,sizeof(hhh),cmp);
        int z=0;           //到达G的人数
        for(int j=0;j<N;j++){
            if(p[j].score>=G)
                z++;
            else
                break;
        }
        printf("case #%d:\n%d\n",i,z);
        for(int j=0;j<z;j++){
            for(int k=0;k<strlen(p[j].s);k++){
                printf("%c",p[j].s[k]);
            }
            printf("\n");
        }

    }
    return 0;
}
