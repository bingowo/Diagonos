#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    int  *s1,*s2;
    s1=(int *)a;
    s2=(int *)b;
    while(*s1!=-1&&*s2!=-1&&*s1==*s2) s1++,s2++;
    return *s2-*s1;
}
int main()
{
    int T;
    scanf("%d\n",&T);
    int i=0;
    for(i=0;i<T;i++)
    {
        int N=0,k=0,j;
        scanf("%d\n",&N);
        int line_data[1000][51];
        for(k=0;k<N;k++)
        {
            j=0;
            while(scanf("%d",&line_data[k][j]) && line_data[k][j]!=-1) j++;
        }
        qsort(line_data,N,sizeof(line_data),cmp);
        for(k=0; k<n; k++)
        {
            for(j=0; line_data[k][j+1]!=-1; j++)
                   printf("%d ",line_data[k][j]);
            printf("%d\n",line_data[k][j]);
        }
    }
    return 0;
}