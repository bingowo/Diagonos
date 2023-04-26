#include<stdio.h>
#include<string.h>
#include<stdlib.h>
unsigned long long RSmax=0;
typedef struct cylin
{
    unsigned long long R;
    long long unsigned H;
    long long unsigned HS;
    long long unsigned RS;
}CYLIN;
int cmpr(const void *a,const void *b)
{

    CYLIN a1=*(CYLIN *)a;
    CYLIN b1=*(CYLIN *)b;
    unsigned long long r1,r2;
    r1=a1.HS+a1.RS-RSmax;r2=b1.HS+b1.RS-RSmax;
    return r1>r2?-1:1;
}
int cmp(const void *a,const void *b)
{
    CYLIN a1=*(CYLIN *)a;
    CYLIN b1=*(CYLIN *)b;
    unsigned long long s1,s2;
    s1=a1.HS;s2=b1.HS;
    if(s1!=s2)return (s1>s2?-1:1);
    else return a1.RS>b1.RS?-1:1;
}
int main()
{
    long long n,m;
    scanf("%lld %lld",&n,&m);
    CYLIN *a=NULL;
    a=(CYLIN*)malloc(sizeof(CYLIN)*n);
    for(long long i=0;i<n;i++){
        scanf("%llu %llu",&a[i].R,&a[i].H);
        a[i].HS=2*a[i].R*a[i].H;
        a[i].RS=a[i].R*a[i].R;
    }
    unsigned long long x=0;
    qsort(a,n,sizeof(CYLIN),cmp);
    for(long long i=0;i<m-1;i++){
        x+=a[i].HS;
        if(a[i].RS>RSmax)RSmax=a[i].RS;
        a[i].HS=0;a[i].RS=0;
    }
    long long judge=0;
    for(int i=m-2;i<n;i++)if(a[i].RS>RSmax)judge+=1;
    if(judge==0)qsort(a,n,sizeof(CYLIN),cmp);
    else qsort(a,n,sizeof(CYLIN),cmpr);
    if(a[0].RS>RSmax)RSmax=a[0].RS;
    x=x+RSmax+a[0].HS;
    printf("%llu",x);
    return 0;
}
