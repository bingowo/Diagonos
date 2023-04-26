#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long int RR;
    long long int RH;
} AAA;

int cmp1(const void* p3,const void* p4)
{
    AAA* p1=(AAA* )p3;
    AAA* p2=(AAA* )p4;
    if((p1->RH)<(p2->RH)) return 1;
    else if((p1->RH)==(p2->RH)){
        if((p1->RR)<(p2->RR)) return 1;
        else return -1;
    }
    else return -1;
}

int cmp2(const void* p3,const void* p4)
{
    AAA* p1=(AAA* )p3;
    AAA* p2=(AAA* )p4;
    if(((p1->RR)+2*(p1->RH))<((p2->RR)+2*(p2->RH))) return 1;
    else return -1;
}

int cmp3(const void* p3,const void* p4)
{
    AAA* p1=(AAA* )p3;
    AAA* p2=(AAA* )p4;
    if((p1->RR)<(p2->RR)) return 1;
    else return -1;
}

int main()
{
    int n=0,m=0;
    scanf("%d %d",&n,&m);
    AAA* p=(AAA* )malloc(n*sizeof(AAA));
    int R=0,H=0;
    for(int i=0;i<n;i++){
        scanf("%d %d",&R,&H);
        (p+i)->RR=((long long int)R)*((long long int)R);
        (p+i)->RH=((long long int)R)*((long long int)H);
    }
    qsort(p,n,sizeof(AAA),cmp1);
    qsort(p,m,sizeof(AAA),cmp3);
    long long int smax=0,a1=(p->RR)+2*((p+m-1)->RH);
    for (int j=0;j<m-1;j++) smax+=2*((p+j)->RH);
    qsort(p,n,sizeof(AAA),cmp2);
    long long int smax1=(p->RR)+2*(p->RH)+smax;
    smax+=a1;
    printf("%lld",smax>smax1 ? smax :smax1);
    free(p);
    return 0;
}
