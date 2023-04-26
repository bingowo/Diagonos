#include<stdio.h>
#include<stdlib.h>
struct student
{
    char xuehao[11];
    int score;
    int solve;
    int right[solve];
};
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int N;
        int M;
        int G;
        int question[M];
        for(int j=0;j<M;j++)
        {
            scanf("%d",&question[j]);
        }
        int x[N];
        struct student stu[N];
        for(int k=0;k<N;k++)
        {
            scanf("%s",&stu[k].xuehao);
            scanf("%d",&stu[k].solve);
            for(int t=0;t<stu[k].solve;t++)
            {
                scanf("%d",&stu[k].right[t]);
                x[k]=x[k]+question[stu[k].right[t]];
            }
            
        }
        int e=0;
        int t=0;
        while(x[t]>G)
        {
            e++;
            t++;
        }
        
    }
}