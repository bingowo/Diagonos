#include<stdio.h>
#include<string.h>

int main()
{
    long long int i=0,j=0,a,b,t=0,qi=0,qr=0,r=0,l=0;
    scanf("%lld+%lldi",&a,&b);
    int c[100000]={0};
    while(qi!=0||qr!=0)
    {
        qi=(-a-b+r)/2;
        qr=(b-a+r)/2;
        a=qr;
        b=qi;
        c[j++]=r;
    }
    l=j;
    for(j=l-1;j>=0;j--)
       printf("%lld",c[j]);
   
    return 0;
}
