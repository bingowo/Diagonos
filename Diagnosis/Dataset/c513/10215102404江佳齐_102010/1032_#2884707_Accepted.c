#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void*b)
{
    int *d1,*d2;
    d1=(int*)a;
    d2=(int*)b;
    while(*d1!=-1 && *d2!=-1 && *d1==*d2) d1++,d2++;
    return *d2-*d1;
}
int main()
{
    int T,n,k;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        int line[1000][51];
        scanf("%d",&N);
        for(n=0;n<N;n++)
        {
            k=0;
            while(scanf("%d",&line[n][k])&&line[n][k]!=-1) k++;
        }
        qsort(line,N,sizeof(line[0]),cmp);
        for(n=0;n<N;n++)
        {
            for(k=0;line[n][k+1]!=-1;k++) printf("%d ",line[n][k]);
            printf("%d\n",line[n][k]);
        }
    }
    return 0;
}
