#include<stdio.h>
long long int Cuber(int n){
	if(n==0)
		return 1;
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	if(n==3)
		return 3;		
	return Cuber(n-1)+Cuber(n-2)+Cuber(n-4);
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld",Cuber(n));
	
	return 0;
}