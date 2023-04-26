#include <stdio.h>

unsigned long long cal(unsigned long long n)
{
	int a[20];
	int i;
	int cnt=0;
	for (i=0;n>0;i++){
		a[i]=n%10;
		n=n/10;
		cnt++;
	}
	unsigned long long sum=0,weight=1;
	for (i=0;i<cnt;i++){
		sum+=a[i]*weight;
		weight*=9;
	}
	return sum;
}

unsigned long long ope(unsigned long long a)
{
	unsigned long long x;
	x=cal(a-a%10)/9;
	unsigned long long y;
	y=a-a%10;
	int i;
	for (i=y;i<=a;i++){
		if(i%9==0){
			x++;
		}
	}
	return x;
}

int main()
{
	unsigned long long a,b;
	scanf("%llu%llu",&a,&b);
	unsigned long long m,n;
	m=cal(a);
	n=cal(b);
	unsigned long long s,t;
	s=ope(a);
	t=ope(b);
	printf("%llu\n",n-m-(t-s)+1);
	return 0;
}