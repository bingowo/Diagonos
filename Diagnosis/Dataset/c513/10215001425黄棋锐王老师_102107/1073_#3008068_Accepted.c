#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long NtT(long long a)//9进制转10进制 
{
	return (a<9)?a:NtT(a/10)*9+a%10;
}
//long long f(long long a)
//{   long long an=NtT(a)+1;//0 to a的9进制数个数； 
//	long long n=an;
//	long long r=n%9,t,i=0;
//	n=n/9;
//	for(t=a-r;t<=a;t++)
//	{  if(t!=0&&t%9==0) i=1;
//	}
//	an=an-n-i;
//	return an;
//}
long long f(long long a) {
    long long d0 = a%10;
    long long x;
    for ( x = a - d0; x <= a; x++) {	 // g in 1096.PPT
        char str[100] = {0};
        sprintf(str, "%lld", x);
        if (x%9 == 0 || strchr(str, '9') != 0) d0--;
    }
    return d0 + 8*NtT(a - a%10)/9;	 // Ans in 1096.PPT
}

int main()
{    long long a,b;
	scanf("%lld %lld",&a,&b);
	long long ans=f(b)-f(a)+1;
//	long long ans=NtT(b)-NtT(a)+1;//a to b的9进制数个数； 
//	long long n=ans;
//	long long r=n%9,t,i=0;
//	n=n/9;
//	for(t=b-r;t<=b;t++)
//	{  if(t!=0&&t%9==0) i=1;
//	}
//	ans=ans-n-i;
	printf("%lld",ans);
	return 0;
}