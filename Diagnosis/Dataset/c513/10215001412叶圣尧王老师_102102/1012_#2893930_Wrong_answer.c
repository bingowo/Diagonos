#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    long long a=0,b=0,qr=0,qi=0;int r[100],k=0,i;
    scanf("%lld",&a);getchar();scanf("%lld",&b);
    while(a!=0&&b!=0)
    {
        if(a%2==b%2)r[k]=0;
        else r[k]=1;
        qr=(b-a+r[k])/2;
        qi=-(a+b-r[k])/2;
        a=qr;
        b=qi;
        k++;
    }
    for(i=k-1;i>=0;i++)printf("%d",r[i]);


}
