#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int abso(long long int a)
{
    if(a<0) return -a;
    else return a;
}
int main()
{
    long long int abso(long long int a);
    long long int a,b,temp;
    char ch;
    int r,count=0;
    int *ans=(int *)malloc(sizeof(int)*1000000000);
    scanf("%lld%c",&a,&ch);
    if(ch=='+') scanf("%lld",&b);
    else if(ch=='-') {scanf("%lld",&temp);b=-temp;}
    else b=0;

    int i=0;
    int qr,qi;
    long long int a1,b1;
    while(1)
    {
        if(a==0&&b==0) break;
        a1=abso(a);
        b1=abso(b);
        if((a1%2)==(b1%2)) r=0;else r=1;
        ans[i++]=r;
        count++;
        qi=(r-a-b)/2;
        qr=(b+r-a)/2;
        a=qr;
        b=qi;
    }
    for(int s=count-1;s>=0;s--) printf("%d",ans[s]);
    return 0;
}
