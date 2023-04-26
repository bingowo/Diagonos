#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct student{
    char ID[12];
    int result;
}*stu;

int cmp(const void *a,const void *b){
    struct student *stu1=(struct student *)a;
    struct student *stu2=(struct student *)b;
    if((stu1->result)!=(stu2->result))
        return ((stu2->result)-(stu1->result));//降序
    else return strcmp(stu1->ID,stu2->ID)>0?1:-1;//升序
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N,M,G;//学生数量，题目数量，分数线
        scanf("%d%d%d",&N,&M,&G);
        stu=(struct student *)malloc(sizeof(struct student)*N);
        int *grade;//每道题的分数
        grade=(int *)malloc(sizeof(int)*M);
        for(int i=0;i<M;i++){
            scanf("%d",&grade[i]);
        }
        int *S;
        S=(int *)malloc(sizeof(int)*N);//答对题数
        for(int i=0;i<N;i++){
            scanf("%s",stu[i].ID);
            scanf("%d",&S[i]);
            int *number;
            number=(int *)malloc(sizeof(int)*S[i]);
            for(int j=0;j<S[i];j++){
                scanf("%d",&number[i]);
                for(int k=0;k<M;k++){
                    if(k+1==number[i]){
                        stu[i].result+=grade[k];
                    }
                }
            }
        }
        qsort(stu,N,sizeof(stu[0]),cmp);
        printf("case #%d:\n",t);
        int count=0;
        for(int i=0;i<N;i++){
            if(stu[i].result>=G)
                count++;
        }
        printf("%d\n",count);
        for(int i=0;i<N;i++){
            if(stu[i].result>=G){
                printf("%s %d\n",stu[i].ID,stu[i].result);
            }
        }
    }
    return 0;
}
