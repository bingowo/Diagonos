#include<stdio.h>
#include<stdlib.h>
struct data{long long int a;
             int number;
             };
int cmp(const void*a,const void* b)
{
    struct data d1,d2;
    d1=*((struct data*)a);
    d2=*((struct data*)b);
    if(d2.number==d1.number)
    {
        if(d1.a>d2.a)return 1;
        else return -1;
    }
    else return d2.number-d1.number;
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        getchar();
        struct data p[10000];
        for(int j=0;j<N;j++)
        {
            scanf("%d",&p[j].a);
        int d;
        d=1;
        p[j].number=0;
        for(int t=0;t<64;t++)
        {
            if(p[j].a&d)p[j].number++;
            d=d<<1;
        }

        }
        qsort(p,N,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++)
        {

            printf("%d%c",p[k].a,(k!=(N-1))?' ':'\n');
        }

    }
    return 0;


}
