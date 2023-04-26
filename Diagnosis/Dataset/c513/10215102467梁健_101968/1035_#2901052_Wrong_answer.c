#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long RSmax=0;
typedef struct cylin
{
    long long R;
    long long H;
    long long HS;
    long long RS;
}CYLIN;
int cmpr(const void *a,const void *b)
{

    CYLIN a1=*(CYLIN *)a;
    CYLIN b1=*(CYLIN *)b;
    long long r1,r2;
    r1=a1.HS+a1.RS-RSmax;r2=b1.HS+b1.RS-RSmax;
    return r1>r2?-1:1;
}
int cmp(const void *a,const void *b)
{
    CYLIN a1=*(CYLIN *)a;
    CYLIN b1=*(CYLIN *)b;
    long long s1,s2;
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
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a[i].R,&a[i].H);
        a[i].HS=2*a[i].R*a[i].H;
        a[i].RS=a[i].R*a[i].R;
    }
    long long x=0;
    qsort(a,n,sizeof(CYLIN),cmp);
    for(int i=0;i<m-1;i++){
        x+=a[i].HS;
        if(a[i].RS>RSmax)RSmax=a[i].RS;
        a[i].HS=0;a[i].RS=0;
    }
    int judge=0;
    for(int i=m-2;i<n;i++)if(a[i].RS>RSmax)judge+=1;
    if(judge<=1)qsort(a,n,sizeof(CYLIN),cmp);
    else qsort(a,n,sizeof(CYLIN),cmpr);
    if(a[0].RS>RSmax)RSmax=a[0].RS;
    x=x+RSmax+a[0].HS;
    printf("%lld",x);
    return 0;
}
