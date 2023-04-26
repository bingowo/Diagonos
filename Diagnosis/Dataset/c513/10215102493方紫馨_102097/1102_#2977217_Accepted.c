#include<stdio.h>
#include<math.h>
int main()
{
	long long n,a,begin,c,x,y,b,k;
	scanf("%lld",&n);
	if(n==0){
		printf("(0,0)");
		return 0;
	}
	b = (long long)sqrt(n);
	if(b%2==0)
		b--;
	begin = b*b;
	a = (b+3)/2;
	c = 2*a-2;
	x = a - 2;
	y = x + 1;
	k = n - begin;
	if(k<0&&k>=-c){
		y = y + k;
	}
	else if(k<=c-1){
		x = x - k;
	}else if(k<=c+c-1){
		x = x - (c-1);
		y = y - (k - c + 1);
	}else if(k<=c+c+c-1){
		x = x - (c-1);
		y = y - c;
		x = x + (k - c - c + 1);
	}else{
		x += 1;
		y = y -c;
		y = y + (k - 3*c + 1);
	}
	printf("(%lld,%lld)",x,y);
	
	return 0;
 } 