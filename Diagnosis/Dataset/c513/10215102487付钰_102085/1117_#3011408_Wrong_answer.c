#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    int x;
    int y;
    int juli;
}pots;
int max1(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int cmp(const void *a,const void *b)
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
    int x0,y0;
    scanf("%d %d",&x0,&y0);
    int n;
    scanf("%d",&n);
    pots a[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i].x,&a[i].y);
        a[i].juli=max1(abs(a[i].x-x0),abs(a[i].y-y0));
        /*if(a[i].juli<min){
            min=a[i].juli;
            x1=a[i].x;
            y1=a[i].y;
        }*/
    }
    qsort(a,n,sizeof(a[0]),cmp);
    printf("%d\n",a[0].juli);
    printf("%d %d\n",a[0].x,a[0].y);
    return 0;
}
