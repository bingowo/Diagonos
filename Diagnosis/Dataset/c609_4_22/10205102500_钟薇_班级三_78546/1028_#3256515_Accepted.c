#include<stdio.h>
#include<stdlib.h>

//排序函数
int cmp(const void *a, const void *b)
{
    int *s1,*s2;
    s1=(int *)a;
    s2=(int *)b;
    while(*s1!=-1 && *s2!=-1 && *s1==*s2)   s1++,s2++;
    return *s2-*s1;
}

int main()
{
    int T;
    scanf("%d",&T);
    int i=0;
    while(T>0)
    {
        T--;       
        int N;
        int j,k;
        int num[1000][51];
        scanf("%d",&N);

        //输入
        for(j=0;j<N;j++)
        {
            k=0;
            while (scanf("%d",&num[j][k]) && num[j][k]!=-1)    k++;
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