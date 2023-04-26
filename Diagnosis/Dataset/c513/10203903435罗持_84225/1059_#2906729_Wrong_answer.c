#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int n,s;
int a[1111] = {0};
int gcd(int x,int y)
{
	if(x%y==0) return y;
	else return(y,x%y);
}
int check(int x)
{
	int tot = 0;
	for(int i=0;i<n;i++) 
	{
		if(x>=a[i]) tot += (x-a[i]);
	}
	if(tot <= s) return 1;
	else return 0;
}
int main(void)
{
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	int low = 0,high = 1000010;
	int mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(check(mid)) low = mid+1;
		else high = mid-1;
	}
	int res = 0;
	if(check(low)) res = low;
	else res = low-1;
	printf("%d",res);
	int len = 0;
	for(int i=0;i<n;i++)
	{
		if(res >=a[i]){
			s -= (res-a[i]);
			len++;
		}
	}
	if(s!=0) 
	{
		putchar('+');
		int g = gcd(len,s);
		printf("%d/%d",s/g,len/g);
	}
	return 0;
}