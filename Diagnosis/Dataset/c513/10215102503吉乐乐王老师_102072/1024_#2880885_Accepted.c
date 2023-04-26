#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
typedef struct{
    char xuehao[12];
    int solve;
    int score;
}student;
int cmp(const void*a,const void *b){
    student x=*(student*)a;
    student y=*(student*)b;
    if(x.score==y.score)return strcmp(x.xuehao,y.xuehao);
    return y.score-x.score;
}
int main(){
    int t;scanf("%d",&t);getchar();
    int idx=0;
    while(t--){
        int nofstu,nofpro,xian;
        scanf("%d %d %d",&nofstu,&nofpro,&xian);getchar();
        int *per=(int *)malloc(sizeof(int)*nofpro);
        for(int i=0;i<nofpro;i++){
            scanf("%d",(per+i));
        }getchar();
        student *stu=(student*)malloc(sizeof(student)*nofstu);
        for(int i=0;i<nofstu;i++){
            scanf("%s",(stu+i)->xuehao);
            scanf("%d",&(stu+i)->solve);
            (stu+i)->score=0;
            for(int j=0;j<(stu+i)->solve;j++){
                int pro;scanf("%d",&pro);
                (stu+i)->score+=per[pro-1];
            }
        }
        qsort(stu,nofstu,sizeof(stu[0]),cmp);
        printf("case #%d:\n",idx++);
        int cnt=0;
        for(int i=0;i<nofstu;i++){
            if(stu[i].score>=xian)cnt++;
        }
        printf("%d\n",cnt);
        for(int i=0;i<nofstu;i++){
            if(stu[i].score>=xian){
                printf("%s %d\n",stu[i].xuehao,stu[i].score);
            }
        }
    }
}