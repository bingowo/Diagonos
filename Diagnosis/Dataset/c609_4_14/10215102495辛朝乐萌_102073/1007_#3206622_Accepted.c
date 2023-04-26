#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct data{
    long long int a;
    int number;
};

int cmp(const void *a,const void *b)
{
    struct data d1,d2;
    d1=*((struct data *)a);
    d2=*((struct data *)b);
    if (d2.number!=d1.number) {
        return d2.number-d1.number;
    }
    else{
        if(d1.a>d2.a){
            return 1;
        }
        else{return -1;}
    }
}

void solve()
{
    int t;
    struct data p[10000];
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        scanf("%lld",&p[i].a);
        long long int d=1;
        p[i].number=0;
        for(int j=0;j<64;j++)
        {
            if(p[i].a&d)
                p[i].number++;
            d=d<<1;
        }
    }
    qsort(p,t, sizeof(p[0]), cmp);
    for (int i=0; i<t; i++) {
        printf("%lld ",p[i].a);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        printf("case #%d:\n",i);
        solve();
    }
    return 0;
}