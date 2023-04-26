#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct problem
{
    long long int a;
    int num;
};

int cmp(const void *a,const void *b)
{
    struct problem b1,b2;
    b1=*((struct problem *)a);
    b2=*((struct problem *)b);
    if (b1.num > b2.num)
        return -1;
    else if (b1.num <b2.num)
        return 1;
    else
    {
        if(b1.a > b2.a)
            return -1;
        else
            return 1;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x;
        struct problem p[10000];
        p[i].num=0;
        scanf("%d",&x);
        for (int j=0;j<x;j++)
        {
            scanf("%lld",&p[j].a);
            long long int k=1;
            for(int t=0; t<64; t++)
            {
                int g=p[j].num;
                long long int h=p[j].a;
                if (p[j].a & k)
                    p[j].num+=1;
                k=k<<1;
            }
        }
        printf("case #%d:\n",i);
        qsort(p,x,sizeof(p[0]),cmp);
        for(int l=0;l<x;l++)
        {
            printf("%lld",p[l].a);
            if(l == x-1)printf("\n");
            else printf (" ");
        }
    }
}

