#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1005

typedef struct
{
    long long R,H;
    long long ds,cs;
}circular;

int cmp_RH(const void* a,const void* b)
{
    circular* ca=(circular*)a;
    circular* cb=(circular*)b;
    if(ca->R!=cb->R)return ca->R<cb->R?1:-1;
    else if(ca->H!=cb->H)return ca->H<cb->H?1:-1;
    else return 0;
}

int cmp_S(const void* a,const void* b)
{
    circular* ca=(circular*)a;
    circular* cb=(circular*)b;
    if(ca->cs+ca->ds!=cb->cs+cb->ds)return ca->cs+ca->ds<cb->cs+cb->ds?1:-1;
    //else if(ca->H!=cb->H)return ca->H<cb->H?1:-1;
    else return 0;
}

int main()
{
    int all_num,cir_num;
    scanf("%d%d",&all_num,&cir_num);
    circular c[N];
    for(int i=0;i<all_num;++i){
        scanf("%lld%lld",&c[i].R,&c[i].H);
        c[i].cs=2*c[i].R*c[i].H;
        c[i].ds=c[i].R*c[i].R;
    }
    qsort(c,all_num,sizeof(c[0]),cmp_S);
    qsort(c,cir_num,sizeof(c[0]),cmp_RH);
    long long max=c[0].ds;
    for(int i=0;i<cir_num;++i)max+=c[i].cs;
    printf("%lld\n",max);
    return 0;
}