#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    int sc;
    char id[12];
}stu;

int cmp(const void*a,const void*b)
{
    stu const*a1=(stu const*)a;
    stu const*b1=(stu const*)b;
    if(a1->sc==b1->sc) return strcmp(a1->id,b1->id);
    else return b1->sc-a1->sc;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        int N,M,G;
        scanf("%d%d%d",&N,&M,&G);
        int a[11];
        for(int j=1;j<M;++j)
        {
            scanf("%d",&a[j]);
        }
        stu stus[500];
        for(int j=0;j<N;++j)
        {
            stus[j].sc=0;
            int x;
            scanf("%s %d",stus[j].id,&x);
            for(int k=0;k<x;++k)
            {
                int y;
                scanf("%d",&y);
                stus[j].sc+=a[y];
            }
        }
        qsort(stus,N,sizeof(stu),cmp);
        int z=0;
        while(stus[z].sc>=G)
        {
            z++;
        }
        printf("case #%d:\n%d\n",i,z);
        for(int j=0;j<z;++j)
        {
            printf("%s %d\n",stus[j].id,stus[j].sc);
        }
    }
    return 0;
}
