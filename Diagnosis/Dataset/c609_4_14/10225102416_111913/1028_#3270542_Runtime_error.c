#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b);
int main()
{
    int T,i,N,j;
    int a[1000][51],s;
    int h=0;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        scanf("%d",&N);
        for(j = 0;j<N;j++)//将N组数据以int类型输入至a中储存
        {
            while(scanf("%d",a[N][h++])!= -1);
            h = 0;
        }
        qsort(a,N,sizeof(a[0]),cmp);
        for(j = 0;j<N;j++)
        {
            while(a[N][h++]!=-1) printf("%s ",a[N][h]);
            printf("\n");
        }
    }
    return 0;
}
int cmp(const void *a, const void *b)
{
    int *A,*B;
    A = (int *)a;
    B = (int *)b;
    while(*A!=-1&&*B!=-1&&*A==*B){
        A++;
        B++;
    }
    return *B-*A;
}
