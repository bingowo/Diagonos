#include <stdio.h>
#include <stdlib.h>

int t[1000][51];


int cmp(const void*a,const void*b)
{
    int*a1,*b1;
    a1=(int*)a;
    b1=(int*)b;
    while(*a1!=-1&&*b1!=-1&&*a1!=*b1)
    {
        (*a1)++;
        (*b1)++;
    }
    return (*b1)-(*a1);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<1000;++i)
        {
            for(int j=0;j<51;++j)
            {
                t[i][j]=-1;
            }
        }
        int N;
        scanf("%d",&N);
        for(int i=0;i<N;++i)
        {
            int j=0;
            int y;
            scanf("%d",&y);
            while(y!=-1)
            {
                t[i][j]=y;
                j++;
                scanf("%d",&y);
            }
        }
        qsort(t,N,sizeof(t[0]),cmp);
        for(int i=0;i<N;++i)
        {
            int j=0;
            while(t[i][j+1]!=-1)
            {
                printf("%d ",t[i][j]);
                j++;
            }
            printf("%d\n",t[i][j]);
        }
    }
    return 0;
}
