#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b);
int main()
{
    int T,i,N,j;
    char a[N][51],s;
    int h=0;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        scanf("%d",&N);
        for(j = 0;j<N;j++)//将N组数据以string类型输入至a中储存
        {
            while(scanf("%s",&s)&&getchar()){
                if(s!="-1") a[N][h++]=s;
                else break;
            }
            h = 0;
        }
        qsort(a,N,sizeof(a[0]),cmp);
        for(j = 0;j<N;j++)
        {
            while(strlen(a[N][h++])!=0) printf("%s ",a[N][h]);
            printf("\n");
        }
    }
    return 0;
}
int cmp(const void *a, const void *b)
{
    char *A,*B;
    A = (char *)a;
    B = (char *)b;
    while(strcmp(*A,*B)==0){
        A++;
        B++;
    }
    return strcmp(*B,*A);
}
