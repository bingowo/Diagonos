#include<stdio.h>
#include<stdlib.h>
struct data
{
    long long int a;
    int number;
};
int cmp(const void*a,const void *b){
    //struct data d1,d2;
    //d1=*((struct data*)a);
    //d2=*((struct data*)b);
    struct data *d1=(struct data*)a;
    struct data *d2=(struct data*)b;
    if(d1->number!=d2->number){
        return d2->number-d1->number;
    }
    else{
        if(d1->a>d2->a){
            return 1;
        }
        else{
            return -1;
        }
    }
};
int main()
{
    struct data p[10010];
    int t,n,i,j;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        scanf("%d\n",&n);
        for(j=0;j<n;j++){
            scanf("%lld ",&p[j].a);
            p[j].number=0;
            long long int d=1;
            for(int m=0;m<64;m++){
                if(p[j].a&d){
                    p[j].number++;
                }
                d=d<<1;
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n-1;j++){
            printf("%lld ",p[j].a);
        }
        printf("%lld\n",p[j].a);
    }
    return 0;
}