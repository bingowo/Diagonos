#include <stdio.h>
#include <stdlib.h>

int cmp(const void *x,const void *y);

struct data{
    long long a;
    int number1;
};

int main()
{
    int T;
    scanf("%d",&T);
    for(int o = 0;o < T;o++){
        struct data p[10000];
        int n;
        scanf("%d",&n);
        printf("case #%d\n",o);
        if(n == 1){
            scanf("%lld",&p[0].a);
            printf("%lld",p[0].a);
        }
        for(int i = 0;i < n;i++){
            scanf("%lld",&p[i].a);
            int d = 1;
            p[i].number1 = 0;
            for(int t = 0;t < 64;t++)
            {
                if(p[i].a & d)p[i].number1++;
                d = d << 1;
            }
            qsort(p,n,sizeof(p[0]),cmp);

            for(int j = 0;j < n - 1;j++)
            {
                printf("%lld",p[i].a);
            }
        }
    }
    return 0;
}


int cmp(const void *x,const void *y)
{
    struct data d1,d2;
    d1 = *((struct data *)x);
    d2 = *((struct data *)y);
    if(d2.number1 != d1.number1)
    {
        return d2.number1 - d1.number1;
    }
    else
    {
        if(d2.a>d1.a)return 1;
        else
            return -1;
    }
}
