#include <stdio.h>
#include <stdlib.h>
int cmp(const void *f,const void *g)
{
    struct data d1,d2;
    d1=*((struct data *)f);
    d2=*((struct data *)g);
    if(d2.number!=d1.number)
        return d2.number-d1.number;
    else
    { if(d1.a>d2.a) return 1;
        else return -1;
    } }

int main(){
    int NUM,num,a=0,b=0,i,d,t;
    long long int shu;
    scanf("%d",&NUM);
    while(a<NUM){
        struct data p[10000];
        scanf("%d",&num);
        for(i=0;i<num;i++)
        { scanf("%lld",&p[i].c);
            d=1;p[i].number=0;
            for(t=0;t<64;t++)
            {
                if(p[i].c&d) p[i].number++;
                d=d<<1;
            }}
        qsort(p,num,sizeof(p[0]),cmp);
        printf("%s", "case #");
        printf("%d:\n", a);
        for(i=0;i<num-1;i++){
            printf("%lld\n", p[i].c);}
        }
    return 0;
}
