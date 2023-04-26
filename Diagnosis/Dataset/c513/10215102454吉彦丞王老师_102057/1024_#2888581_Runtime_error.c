#include<stdio.h>
#include<stdlib.h>
struct student
{
    char xuehao[11];
    int score;
    int solve;
};
int cmp(const void *pa,const void *pb)
{
    struct student a,b;
    a=*((struct student *)pa);
    b=*((struct student *)pb);
    if(a.score!=b.score)
    {
        return b.score-a.score;
    }
    else
    {
        return (a.xuehao[10]-'0')-(b.xuehao[10]-'0');
    }
} 
int main()
{
    int number;
    scanf("%d",&number);
    int N[number];
    int M[number];
    int G[number];
    int e[number];
    struct student stu[number][1000];
    for(int i=0;i<number;i++)
    {
        scanf("%d",&N[i]);
        scanf("%d",&M[i]);
        scanf("%d",&G[i]);
        int question[M[i]];
        for(int j=0;j<M[i];j++)
        {
            scanf("%d",&question[j]);
        }

        for(int k=0;k<N[i];k++)
        {
            for(int h=0;h<11;h++)
            {
            	scanf("%c",&stu[i][k].xuehao[h]);
			}
            scanf("%d",&stu[i][k].solve);
            int right[stu[i][k].solve];
            for(int t=0;t<stu[i][k].solve;t++)
            {
                scanf("%d",&right[t]);
            }
            int r=0;
            for(int z=0;z<stu[i][k].solve;z++)
            {
            	r=r+right[z];
			}
			stu[i][k].score=r;
        }
        int t=0;
        for(int u=0;u<N[i];u++)
        {
        	if (stu[i][u].score>G[i]);
        	{
        		t++;
			}
		}
		e[i]=t;
        qsort(stu[i],N[i],sizeof(stu[0]),cmp);

    }
    for(int i=0;i<number;i++)
    {
    	printf("case #%d:\n",i);
    	printf("%d\n",e[i]);
    	for(int j=0;j<e[i];j++)
    	{
    		for(int t=0;t<11;t++)
    		{
    			printf("%c",stu[i][N[i]].xuehao[j]);
			}
			printf(" %d\n",stu[i][N[i]].score);
		}
	}
    return 0;
}