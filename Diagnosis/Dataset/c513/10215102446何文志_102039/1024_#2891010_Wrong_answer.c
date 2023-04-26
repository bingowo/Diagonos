#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student
{
    char num[12];
    int ques[10];
    int score;
}student;

int getScore(int MList[],int S,int ques[])
{
    if(S == 0){return 0;}
    int ans = 0;
    for(int i = 0;i<S;i++)
    {
        ans+=MList[ques[i]-1];
    }
    return ans;
}

int cmp1(const void *a,const void *b)
{
    student A = *(student*)a,B = *(student*)b;
    //printf("cmp A = %d, B = %d\n",A.score,B.score);
    if(A.score!=B.score){return B.score-A.score;}
    else{return strcmp(A.num,B.num);}
}


int main()
{
    int T = 0;
    scanf("%d",&T);
    int i = 0;
    for(i = 0;i<T;i++)
    {
        int N = 0,M = 0,G = 0;
        int Gans = 0;
        scanf("%d%d%d",&N,&M,&G);
        student stu[N];memset(stu,0,N*sizeof(student));
        int MList[M];memset(MList,0,M*sizeof(int));
        for(int j = 0;j<M;j++)
        {
            scanf("%d",&MList[j]);
        }
        for(int k = 0;k<N;k++)
        {
            scanf("%s",stu[k].num);
            int S = 0;
            scanf("%d",&S);
            for(int k1 = 0;k1<S;k1++)
            {
                scanf("%d",&stu[k].ques[k1]);
            }
            stu[k].score = getScore(MList,S,stu[k].ques);
            if(stu[k].score>=G){Gans++;}
        }
        qsort(stu,N,sizeof(stu[0]),cmp1);
        for(int i1 = 0;i1<N;i1++)
        {
            if(stu[i1].score>=G)
            {
                printf("%s %d\n",stu[i1].num,stu[i1].score);
            }

        }

        printf("case #%d:\n",i);
        printf("%d\n",Gans);



    }
    return 0;
}
