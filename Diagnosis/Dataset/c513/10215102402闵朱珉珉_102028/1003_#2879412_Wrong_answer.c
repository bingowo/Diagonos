#include <stdio.h>
#include <stdlib.h>
struct res{long long int a;int b;};
int cmp(const void *a,const void *b)
{
    struct res res1,res2;
    res1=*((struct res *)a);
    res2=*((struct res *)b);
    if (res1.b!=res2.b) return res2.b-res1.b;
    else 
    {
        if (res1.a==res2.a) return -1;
        else return res1.a-res2.a;
    }

}
int main()
{
    int T,N,k=0;
    scanf ("%d",&T);
    struct res s[10000];
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",k++);
        scanf("%d",&N);
        for (int i=0;i<N;i++)
        {
            scanf("%lld",&s[i].a);
            long long int q=1;
            s[i].b=0;
            for (int i=0;i<64;i++)
            {
                if (s[i].a & q) s[i].b++;
                q=q<<1;
            }
        }
        qsort (s,N,sizeof(s[0]),cmp);
        for (int i=0;i<N;i++)
            printf("%lld ",s[i].a);
        printf("\n");

    }

    return 0;
}

