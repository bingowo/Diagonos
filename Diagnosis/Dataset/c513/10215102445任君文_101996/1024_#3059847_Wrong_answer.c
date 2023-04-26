#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int T;
    int N,M,G;
    int score[10]={0},mark[500]={0},n=0,temp=0,sum=0;
    char number[500][11]={0};
    int i,j,k;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #:%d\n",i);
        scanf("%d%d%d",&N,&M,&G);
        for(j=0;j<M;j++)
        {
            scanf("%d",&score[j]);
        }
        for(j=0;j<N;j++)
        {
            n=0;
            sum=0;
            temp=0;
            scanf("%s%d",&number[j],&n);
            for(k=0;k<n;k++)
            {
                scanf("%d",&temp);
                sum=sum+score[temp];
            }
            if(sum>=G)
            {
                mark[j]=sum;
                printf("%s\n",number[j]);
            }
            else
            {
                j--;
                N--;
            }
        }
        
    }
	return 0;
}