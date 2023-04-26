#include <stdio.h>
int gcd(int a, int b)
{
	return b?gcd(b,a%b):a; 
}
int main()
{
	int n; scanf("%d",&n);
	int a=0,b=1,i;
	for(i=0 ; i<n ; i++)
	{
		int c,d;
		scanf("%d/%d",&c,&d);
		a = a*d+b*c; b = b*d;
		a /= gcd(a,b); b /= gcd(a,b);
	}
	printf("%d/%d",a,b);
	return 0;
 } 