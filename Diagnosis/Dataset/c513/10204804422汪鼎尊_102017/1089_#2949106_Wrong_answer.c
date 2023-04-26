#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main()
{
	int i,j;
	long long a,result=1;
	int b,n;
	int ca,cases;
	char fmt[10]="%00lld\n";
	scanf("%d",&cases);
	for(ca=0;ca<cases;ca++)
	{
		result=1;
		scanf("%lld %d %d",&a,&b,&n);
		for(i=0;i<b;i++)result=(result*a)%((int)pow(10,n));
		fmt[2]=n+'0';
		printf(fmt,result);
	}
    return 0;
}