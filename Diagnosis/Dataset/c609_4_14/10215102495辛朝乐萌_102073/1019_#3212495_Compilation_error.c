#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int shu;
    int number;
}data;

int cal(data n)
{
    if (n.shu<0) n.shu=-n.shu;
    mm=0;
    while (n.shu){
        mm++;
        n.shu/=10;
    }
    
    return mm;
}



int cmp(const void *a,const void *b)
{
    data m=*((data *)a);
    data n=*((data *)b);
    int xx=cal(n);
    int cc=cal(m);
    if( xx != cc) {return xx-cc;}
    else return m.shu-n.shu;
}

int main()
{
    data a[1000000];
    int n=0;
    while (scanf("%d",&a[++n].shu)!=EOF);
    qsort(a,n,sizeof(a[0]),cmp);
    for (int i = 0; i < n; ++i) {
        printf("%d ",a[i].shu);
    }
    return 0;
}