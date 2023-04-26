#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    int *c=(int *)a;
    int *d=(int *)b;
    while(*c!=-1 && *d!=-1 && *c==*d) c++,d++;
    return *d-*c;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int line_data[1000][51];
        int N,j,k;
        scanf("%d",&N);
        for(k=0;k<N;k++)
        {
            j=0;
            while(scanf("%d",&line_data[k][j]) && line_data[k][j]!=-1) j++;
        }
        qsort(line_data,N,sizeof(line_data[0]),cmp);
        //printf("case #%d:\n",i);
        for(k=0;k<N;k++)
        {
            for(j=0;line_data[k][j+1]!=-1;j++)
            {
                printf("%d ",line_data[k][j]);
            }
            printf("%d\n",line_data[k][j]);
        }
    }
    return 0;
}
