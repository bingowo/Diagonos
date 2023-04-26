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
    int m,n,i,j;
    scanf("%d %d",&m,&n);
    struct data cir[2000];
    long int sum=0,mid[2000];
    for(i=0;i<m;i++)
    {
        scanf("%ld %ld",&(cir[i].r),&(cir[i].h));
        cir[i].area=2*cir[i].r*cir[i].h;
        cir[i].mid=cir[i].area+cir[i].r*cir[i].r;
    }
    for(i=0;i<m;i++)
    {
        struct data m1;
        m1=cir[i];cir[i]=cir[m-1];cir[m-1]=m1;
        sum=cir[m-1].mid;
        qsort(cir,m-1,sizeof(cir[0]),cmp1);
        for(j=0;j<n-1;j++)
            sum+=cir[j].area;
        mid[i]=sum;
    }
    qsort(mid,m,sizeof(mid[0]),cmp2);
    printf("%ld",mid[0]);
    return 0;
}

