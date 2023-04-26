#include<stdio.h>

void f(int n,int r){
	if(n==0)
		return;
	int m=n%r;
	if(m<0){
		m=m-r;
		n=n+r;
	}
	if(m>=10)
		m='A'+m-10;
	else
		m=m+'0';
	f(n/r,r);
	printf("%c",m);
	return;
}
int main()
{
	int N,R;
	scanf("%d %d",&N,&R);
	if(N==0)
		printf("0");
	else
		f(N,R);
	return 0;
 } 