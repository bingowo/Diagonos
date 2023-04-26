#include <stdio.h>
#include <stdlib.h>

struct data{
    long long a;
    int number1;
};

int cmp(const void *a,const void *b)
{
    struct data x,y;
    x = *((struct data *)a);
    y = *((struct data *)b);
    if(x.number1 != y.number1){
        return y.number1 - x.number1;
    }
    else{
        if(x.a > y.a)return 1;
        else
            return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int n;
        scanf("%d",&n);
        struct data q[10000];
        for(int i=0;i<n;i++){
            scanf("%lld",&q[i].a);
            int count=0;
            long long x=1;
            for(int j=0;j<64;j++){
                if(q[i].a & x)count++;
                x = x << 1;
            }
            q[i].number1 = count;
        }
        qsort(q,n,sizeof(q[0]),cmp);
        for(int i=0;i<n;i++){
            printf("%lld ",q[i].a);
        }
        printf("\n");
    }
    return 0;
}
