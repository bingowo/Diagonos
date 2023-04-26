#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    long long int x;
    long long int y;
}DIR;

int cmp(const void* p3,const void* p4)
{
    DIR* p1=(DIR* )p3;
    DIR* p2=(DIR* )p4;
    unsigned long long int len1=llabs(p1->x)+llabs(p1->y);
    unsigned long long int len2=llabs(p2->x)+llabs(p2->y);
    if(len1<len2) return 1;
    else if(len1>len2) return -1;
    else{
        if((p1->x)>(p2->x)) return 1;
        else if((p1->x)<(p2->x)) return -1;
        else{
            if((p1->y)>(p2->y)) return 1;
            else return -1;
        }
    }
}

int main()
{
    int n=0;
    scanf("%d",&n);
    DIR* p=(DIR* )malloc(n*sizeof(DIR));
    for(int i=0;i<n;i++) scanf("%lld %lld",&((p+i)->x),&((p+i)->y));
    qsort(p,n,sizeof(DIR),cmp);
    unsigned long long int m=llabs(((p+1)->x)-(p->x))+llabs(((p+1)->y)-(p->y));
    printf("%llu\n",m);
    long long int bushu=0;
    for(int j=1;j<n;j++){
        m=llabs(((p+j)->x)-((p+j-1)->x))+llabs(((p+j)->y)-((p+j-1)->y));
        if((m-1)%2!=0) break;
        long long int nn=1;
        while(m>nn-1){
            nn*=2;
            bushu++;
        }
    }
    printf("%lld",bushu);
    return 0;
}
