#include <stdio.h>
#include <stdlib.h>

struct data
{
    long int r;
    long int h;
    long int area;

};

int cmp2(const void* a,const void* b)
{
    long int d1,d2;
    int t;
    d1=*((long int*)a),d2=*((long int*)b);
    if(d1<d2) t=1;
    else t=-1;
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
    for(i=0;i<m;i++)
    {
        scanf("%ld %ld",&(cir[i].r),&(cir[i].h));
        cir[i].area=2*cir[i].r*cir[i].h;
    }
    qsort(cir,m,sizeof(cir[0]),cmp1);
    long int sum=0,mid[2000];
    for(i=0;i<n-1;i++)
        sum+=cir[i].area;
    for(i=n-1;i<m;i++)
        mid[i-n+1]=cir[i].area+cir[i].r*cir[i].r;
    qsort(mid,m-n+1,sizeof(mid[0]),cmp2);
    printf("%ld",sum+mid[0]);
    return 0;
}

