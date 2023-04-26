#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct cylin
{
    long long R;
    long long H;
    long long HS;
}CYLIN;
int cmpr(const void *a,const void *b)
{

    CYLIN a1=*(CYLIN *)a;
    CYLIN b1=*(CYLIN *)b;
    long long r1,r2;
    r1=a1.R;r2=b1.R;
    return r1>r2?-1:1;
}
int cmp(const void *a,const void *b)
{
    CYLIN a1=*(CYLIN *)a;
    CYLIN b1=*(CYLIN *)b;
    long long s1,s2;
    s1=a1.HS;s2=b1.HS;
    return (s1>s2?-1:1);
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
    }
    qsort(a,n,sizeof(CYLIN),cmpr);
    long long x=0;
    x=a[0].R*a[0].R+a[0].R*2*a[0].H;
    a[0].HS=0;
    qsort(a,n,sizeof(CYLIN),cmp);
    for(int i=0;i<m-1;i++){
        x=a[i].HS+x;
    }
    printf("%lld",x);
    return 0;
}
