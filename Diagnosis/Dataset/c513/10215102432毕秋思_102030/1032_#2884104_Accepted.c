#include <stdlib.h>

int cmp(const void*a,const void *b)
{
    int *s1,*s2;
    s1=(int *)a;
    s2=(int *)b;
    while(*s1!=-1 && *s2!=-1 && *s1==*s2)
    {
        s1++;
        s2++;
    }
    return *s2-*s1;
}

int func(void)
{
    int N=0;
    scanf("%d\n",&N);
    int line_data[1000][51]={0};
    for(int i=0;i<N;i++)
    {
        int j=0;
        while(scanf("%d",&line_data[i][j])&&line_data[i][j]!=-1) j++;
    }
    qsort(line_data,N,sizeof(line_data[0]),cmp);
    for(int k=0;k<N;k++)
    {
        int t=0;
        for(t=0;line_data[k][t+1]!=-1;t++)
        {
            printf("%d ",line_data[k][t]);
        }
        printf("%d\n",line_data[k][t]);
    }
}

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        func();
    }
    return 0;
}
