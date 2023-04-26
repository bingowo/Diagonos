#include<stdio.h>
#include<stdlib.h>

//排序函数
int cmp(const void *a, const void *b)
{
    int *x,*y;
    x=(int *)a;
    y=(int *)b;
    while(*x!=-1 && *y!=-1 && *x==*y)   x++,y++;
    return *y-*x;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T>0)
    {
        T--;       
        int num[1000][51];
        int N;
        int j,k;
        scanf("%d",&N);

        //输入
        for(j=0;j<N;j++)
        {
            k=0;
            while (scanf("%d",&num[j][k]) && num[j][k]!=-1)    j++;
        }

        //排序
        qsort(num,N,sizeof(num[0]),cmp);

        //输出
        for(j=0;j<N;j++)
        {
            for(k=0;num[j][k+1]!=-1;k++)
                printf("%d ",num[j][k]);
            printf("%d\n",num[j][k]);
        }        
    }
    return 0;
}