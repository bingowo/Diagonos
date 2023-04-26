#include <stdio.h>
#include <stdlib.h>

int t[1000][51];

int cmp(const void*a,const void*b)
{
    int*a1,*b1;
    a1=(int*)a;
    b1=(int*)b;
    while((*a1)!=-1&&(*b1)!=-1&&(*a1)==(*b1))
    {
        a1++;
        b1++;
    }
    return (*b1)-(*a1);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        for(int i=0;i<N;++i)
        {
            int j=0;
            while(scanf("%d",&t[i][j])&&t[i][j]!=-1) j++;
        }
        qsort(t,N,sizeof(t[0]),cmp);
        for(int i=0;i<N;++i)
        {
            int j=0;
            for(;t[i][j+1]!=-1;++j)
            {
                printf("%d ",t[i][j]);;
            }
            printf("%d\n",t[i][j]);
        }
    }
    return 0;
}
