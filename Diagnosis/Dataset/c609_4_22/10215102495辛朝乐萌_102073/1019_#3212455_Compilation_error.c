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
    n.number=0;
    while (n.shu){
        n.number++;
        n.shu/=10;
    }
    
    return n.number;
}



int cmp(const void *a,const void *b)
{
    data m=*((data *)a);
    data n=*((data *)b);
    int xx=cal(n),cc=cal(m);
    if(m.number != n.number) {xx-cc;}
    else return return m.shu-n.shu;
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