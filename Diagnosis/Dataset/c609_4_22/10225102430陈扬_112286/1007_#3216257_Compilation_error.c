#include <stdio.h>
#include <stdlib.h>
struct data {
    long long int a;
    int number;
    };
int cmp(const void *a,const void *b) { struct data d1,d2; d1=*((struct data *)a); d2=*((struct data *)b); if(d2.number!=d1.number)  return d2.number-d1.number; else {    if(d1.a>d2.a) return 1; else return -1; } }
int main()
{
    int T,N,d=1,number=0;
    struct data p[10001];
    scanf("%d",&T);
    for (int i=0;i<T;i++）{
        scanf（"%d",&N);
        for (int j=0;j<N;j++){
            scanf("%lld ",&p[j].a);
        }
        for (int k=0;k<j;k++){
            for(int l=0;l<j:l++){
               if(p[k]&d){ p[k].num++;}
               d<<1;
            }

        }
        qsort(p,j,sizeof(p[0]),cmp);
        for(q=0;q<n-1;q++){
            printf("%lld ",p[q].a);
        }
    }
    return 0;
}
