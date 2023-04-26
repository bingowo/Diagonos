#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    long long int x;
    long long int y;
    long long int juli;
}pots;
long long int max1(long long int a,long long int b)
{
    if(a>b) return a;
    else return b;
}
long long int cmp(const void *a,const void *b)
{
    pots*p1=(pots*)a;
    pots*p2=(pots*)b;
    if(p1->juli!=p2->juli){
        return p1->juli-p2->juli;
    }
    else if(p1->x!=p2->x){
        return p1->x-p2->x;
    }
    else return p1->y-p2->y;
}

int main()
{
    long long int x0,y0;
    scanf("%lld %lld",&x0,&y0);
    long long int n;
    scanf("%lld",&n);
    pots a[n];
    for(long long int i=0;i<n;i++){
        scanf("%lld %lld",&a[i].x,&a[i].y);
        a[i].juli=max1(abs(a[i].x-x0),abs(a[i].y-y0));
        /*if(a[i].juli<min){
            min=a[i].juli;
            x1=a[i].x;
            y1=a[i].y;
        }*/
    }
    qsort(a,n,sizeof(a[0]),cmp);
    printf("%lld\n",a[0].juli);
    printf("%lld %lld\n",a[0].x,a[0].y);
    return 0;
}
