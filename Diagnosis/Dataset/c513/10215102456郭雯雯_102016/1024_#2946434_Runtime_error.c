#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stu{
    char num[15];int fen;//学号，得分
};
int cmp(const void *a,const void *b){
    struct stu *g1=(struct stu*)a,*g2=(struct stu*)b;
    int t=g1->fen-g2->fen;
    return t;
}
int main(){
    int t,a=0;
    scanf("%d",t);
    while(a<t){
        int n,m,g,s,k,j=0;//s为学生解出的题目总数,k为学生答对题目编号
        struct stu std[n];
        scanf("%d %d %d",&n,&m,&g);
        int score[m+1];score[0]=0;
        for(int i=1;i<=m;i++)scanf("%d",&score[i]);
        for(int i=0;i<n;i++){
            std[i].fen=0;
            scanf("%s",std[i].num);scanf("%d",&s);
            while(s--){
                scanf("%d",&k);
                std[i].fen+=score[k];
            }
        }
        qsort(std,n,sizeof(struct stu),cmp);
        printf("case #%d:\n",a);
        for(int i=0;i<n;i++)
            if(std[i].fen>=g)j++;
        printf("%d\n",j);
        for(int i=0;i<n;i++)
            if(std[i].fen>=g)printf("%s %d\n",std[i].num,std[i].fen);
        a++;
    }
}