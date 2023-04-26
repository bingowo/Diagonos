#include <stdio.h>
#include <stdlib.h>
struct res{long long int a;int b;};
int cmp(const void *a,const void *b)
{
    struct res res1,res2;
    res1=*((struct res *)a);
    res2=*((struct res *)b);
    if (res1.b==res2.b) {if (res1.a==res2.a) return -1;else return res1.a-res2.a;}
    else return res2.b-res1.b;

}
int main()
{
    int T,N;
    scanf ("%d",&T);
    struct res s[10000];
    for (int i=0;i<T;i++)
    {
        int k=0;
        scanf("%d",&N);
        for (int i=0;i<N;i++)
        {
            scanf("%lld",&s[i].a);
            int sum=0,q=1;
            for (int i=0;i<64;i++)
            {
                if (s[i].a&q) sum++;
                q=q<<1;
            }
            s[i].b=sum;
        }
        qsort (s,N,sizeof(s[0]),cmp);
        printf("case #%d:\n",k);
        k++;
        for (int i=0;i<N;i++)
            printf("%lld ",s[i].a);
        printf("\n");

    }

    return 0;
}

