#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int *s1,*s2;
    s1=(int *)a;
    s2=(int *)b;
    while(*s1!=-1&&*s2!=-1&&*s1==*s2) s1++,s2++;
    return *s2-*s1;
}
int main()
{
    int T,a;
    scanf("%d",&T);
    for(a=0;a<T;a++) //a表示每个问题
    {
        int line_data[1000][50];
        int N,i,j; //i表示行，j表示列，N表示总行数
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            j=0;
            while(scanf("%d",&line_data[i][j])&&line_data[i][j]!=-1) j++;
        }
        qsort(line_data,N,sizeof(line_data[0]),cmp);
        for(i=0;i<N;i++)
        {
            for(j=0;line_data[i][j]!=-1;j++)
            {
                printf("%d ",line_data[i][j]);
            }
            printf("\n")
        }
    }
}
