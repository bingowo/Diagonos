#include <stdio.h>
#include <stdlib.h>
int f(long long a[],long long b[])
{
    long long max=4611686018427387904;
    int x=0;
    if((a[0]==max&&b[0]==-max)||(b[0]==max&&a[0]==-max))
        x=1;
    if((a[1]==max&&b[1]==-max)||(b[1]==max&&a[1]==-max)&&x==0)
        x=2;
    else if((a[1]==max&&b[1]==-max)||(b[1]==max&&a[1]==-max)&&x==1)
        x=3;
    return x;
}
unsigned long long m(long long a[],long long b[])
{
    unsigned long long max=9223372036854775808;
    long long x,y;
    x=a[0]-b[0];
    y=a[1]-b[1];
    if(x<0)
        x=-x;
    if(y<0)
        y=-y;
    if(f(a,b)==1)
        return max+y;
    else if(f(a,b)==2)
        return x+max;
    else
        return x+y;
}
int cmp(const void *a,const void *b)
{
    long long *a0=(long long*)a;
    long long *b0=(long long*)b;
    long long c0[2]={0,0};
    if(m(a0,c0)<m(b0,c0))
        return 1;
    else if(m(a0,c0)>m(b0,c0))
        return -1;
    else if(a0[0]>b0[0])
        return 1;
    else if(a0[0]<b0[0])
        return -1;
    else if(a0[1]>b0[1])
        return 1;
    else
        return -1;
}
int main()
{
    long long a[100][2];
    unsigned long long s;
    int i,n,x;
    scanf("%llu",&n);
    for(i=0;i<n;i++)
        scanf("%lld%lld",&a[i][0],&a[i][1]);
    qsort(a,n,sizeof(a[0]),cmp);
    if(f(a[0],a[1])==3)
        printf("18446744073709551616\n");
    else
        printf("%llu\n",m(a[0],a[1]));
    i=0;
    x=0;
    while(i<n-1){
        s=m(a[i],a[i+1]);
        if(f(a[i],a[i+1])==3||s%2==0)
            break;
        while(s>1){
            if(s%4==1){
                s=(s+1)/2;
                x++;
            }
            else if(s%4==3){
                s=(s-1)/2;
                x++;
            }
        }
        x++;
        i++;
    }
    printf("%d\n",x);
    return 0;
}
