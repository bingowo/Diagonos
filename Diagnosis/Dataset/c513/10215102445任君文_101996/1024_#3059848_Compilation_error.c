#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void swap(int* a, int*b)
{
    int t =*a;
    *a=*b;
    *b=t;
}
int main()
{
    int T;
    int N,M,G;
    int score[10]={0},mark[500]={0},n=0,temp=0,sum=0,p[j]={0};
    char number[500][11]={0};
    int i,j,k;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
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
            }
            else
            {
                j--;
                N--;
            }
        }
        printf("case #:%d\n",i);
        if(N==0)
        {
            printf("%d\n",N);
        }
        else
        {
            for(j=0;j<N;j++)
            {
                p[j]=j;
            }
            for(j=0;j<N-1;j++)
            {
                for(k=0;k<N;k++)
                {
                    if(mark[p[k]]<mark[p[k+1]])
                    {
                        swap(&p[k],&p[k+1]);
                    }
                    else if(mark[p[k]]==mark[p[k+1]])
                    {
                        if(strcmp(number[p[k]],number[p[k+1]])>0)
                        {
                            swap(&p[k],&p[k+1]);
                        }
                    }
                }
            }
            for(j=0;j<N;j++)
            {
                printf("%s %d\n",number[p[j]],mark[p[j]]);
            }
        }
    }
	return 0;
}