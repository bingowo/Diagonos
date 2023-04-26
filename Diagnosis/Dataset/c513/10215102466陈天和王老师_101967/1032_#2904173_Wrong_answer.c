#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b);
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int N;
        int a[1001][51];

        scanf("%d",&N);
        int i=0,j=0;
        for(i=0;i<N;i++){
            while(scanf("%d",&a[i][j]) && a[i][j]!=-1) j++;
        }//输入

        qsort(a,N,sizeof(a[0]),cmp);

        for(i=0;i<N;i++){
            for(j=0;a[i][j]!=-1;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }//输出
    }
    return 0;
}


int cmp(const void*a,const void*b){
    int *p,*q;

    p=(int*)a;
    q=(int*)b;
    while(*p==*q && *p!=-1 && *q!=-1)  p++,q++;
    return *q-*p;
}
//整型数范围是2*10的九次幂，longlong可以达到
//int a[1001][51]={-1};可以把所有元素初始化为-1吗
//== and  =
//重复使用变量名称
//输入数组时要加取地址符号
