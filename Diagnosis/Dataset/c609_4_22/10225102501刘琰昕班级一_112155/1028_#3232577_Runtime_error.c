#include <stdio.h>
#include <stdlib.h>

int cmp(const void *_num1,const void *_num2)
{
    int *num1=*(int **)_num1;
    int *num2=*(int **)_num2;
    int i=0;
    while(num1[i]!=-1&&num2[i]!=-1)
    {
        if(num1[i]!=num2[i])
            return num1[i]>num2[i]?-1:1;
        i++;
    }
    if(num1[i]==-1)return 1;
    else return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int Case=0;Case<T;Case++)
    {
        int N;
        scanf("%d",&N);
        int **num=(int **)malloc(N*sizeof(int *));
        for(int i=0;i<N;i++)
        {
            num[i]=(int *)malloc(50*sizeof(int));
            int n=0;
            while(scanf("%d",&num[i][n])&&num[i][n]!=-1)
                n++;
        }
        qsort(num,N,sizeof(int **),cmp);
        for(int i=0;i<N;i++)
        {
            for(int j=0;num[i][j]!=-1;j++)
                printf("%d ",num[i][j]);
            printf("\n");
            free(num[i]);
        }
        free(num);
    }
    return 0;
}
