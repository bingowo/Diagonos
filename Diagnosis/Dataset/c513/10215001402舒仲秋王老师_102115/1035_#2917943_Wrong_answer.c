#include <stdio.h>
#include <stdlib.h>

struct data
{
    long int r;
    long int h;
    long int area;
    long int mid;

};

int cmp2(const void* a,const void* b)
{
    struct data d1,d2;int t;
    d1=*((struct data*)a),d2=*((struct data*)b);
    if(d1.mid<d2.mid) t=-1;
    else t=1;
    return t;
}

int cmp1(const void* a,const void* b)
{
    struct data d1,d2;int t;
    d1=*((struct data*)a),d2=*((struct data*)b);
    if(d1.area>d2.area) t=-1;
    else t=1;
    return t;
}

int main()
{
    int m,n,i;
    scanf("%d %d",&m,&n);
    struct data cir[2000];
    long int sum=0;
    for(i=0;i<m;i++)
    {
        scanf("%ld %ld",&(cir[i].r),&(cir[i].h));
        cir[i].area=2*cir[i].r*cir[i].h;
        cir[i].mid=cir[i].area+cir[i].r*cir[i].r;
    }
    qsort(cir,m,sizeof(cir[0]),cmp2);
    sum=cir[m-1].mid;
    qsort(cir,m-1,sizeof(cir[0]),cmp1);
    for(i=0;i<n-1;i++)
        sum+=cir[i].area;
    printf("%ld",sum);
    return 0;
}

