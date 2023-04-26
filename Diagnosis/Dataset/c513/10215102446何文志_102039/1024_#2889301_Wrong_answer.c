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

int cmp(const void *a,const void *b)
{
    student A = *(student*)a,B = *(student*)b;
    if(A.score!=B.score){return A.score>B.score;}
    else
    {
        return strcmp(A.num,B.num);
    }
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
        //printf("%d %d %d\n",N,M,G);
        student stu[N];memset(stu,0,N*sizeof(student));
        student *pStu[N];memset(pStu,0,N*sizeof(student*));
        int MList[M];memset(MList,0,M*sizeof(int));
        for(int j = 0;j<M;j++)
        {
            scanf("%d",&MList[j]);
            //printf("%d ",MList[j]);
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
            //printf("score = %d\n",stu[k].score);
            if(stu[k].score>=G){;pStu[Gans++] = &stu[k];}
        }

        qsort(pStu,Gans,sizeof(student*),cmp);


        //printf("pstu = %s\n",pStu[0]->num);
        printf("case #%d\n",i);
        printf("%d\n",Gans);
        for(int i1 = 0;i1<Gans;i1++)
        {
            printf("%s %d\n",pStu[i1]->num,pStu[i1]->score);
        }


    }
    return 0;
}
