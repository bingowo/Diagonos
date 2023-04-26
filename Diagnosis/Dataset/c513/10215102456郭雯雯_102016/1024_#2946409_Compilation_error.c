#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stu{
    char num[15];int fen;//学号，得分
};
int cmp(const void *a,const void *b){
    struct std *g1=(struct std*)a,*g2=(struct std*)b;
    int t=g1->fen-g2->fen;
    return t;
}
int main(){
    int t,a=0;
    while(a<t){
        int n,m,g,s,k,j;//s为学生解出的题目总数,k为学生答对题目编号
        struct stu std[n];
        scanf("%d %d %d",&n,&m,&g);
        int score[m+1];score[0]=0;
        for(int i=1;i<=m;i++)scanf("%d",&score[i]);
        for(int i=0;i<n;i++){
            scanf("%s",std[i].num);scanf("%d",&s);
            while(s--){
                scanf("%d",&k);
                std[i].fen+=score[k];
            }
        }
        qsort(std,n,sizeof(struct std),cmp);
        for(int i=0;i<n;i++){
            if(std[i].fen>=g)printf("%s %d",std[i].num,std[i].fen);
        }
        a++;
    }
}