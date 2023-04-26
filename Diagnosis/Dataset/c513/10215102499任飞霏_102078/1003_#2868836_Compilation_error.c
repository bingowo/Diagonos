#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b);

struct data{
    long long a;
    int number1;
};

int main()
{
    int T;
    scanf("%d",&T);
    struct data p[10000];
    int n;
    for(int o = 0;o < T;o++){
        scanf("%d",&n);
        printf("case #%d:\n",o);
        
        else{
            for(int i = 0;i < n;i++){
            scanf("%lld",&p[i].a);
            int d = 1;
            p[i].number1 = 0;
            for(int t = 0;t < 64;t++)
            {
                if(p[i].a & d)p[i].number1++;
                d = d << 1;
            }
            //printf("%d\n",p[i].number1);
        }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        int j;
        for(j = 0;j < n - 1;j++)
        {
            printf("%lld ",p[j].a);
        }
        printf("%lld\n",p[j].a);
    }
    return 0;
}


int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1 = *((struct data *)a);
    d2 = *((struct data *)b);
    if(d2.number1 != d1.number1)
    {
        return d2.number1 - d1.number1;
    }
    else
    {
        if(d1.a>d2.a)return 1;
        else return -1;
    }
}
