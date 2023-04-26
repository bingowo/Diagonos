#include <stdio.h>
char number[]="0123456789ABCDEFGHIJ";
void f(int m,int n)
{
	while (m/n)
	{
		if ((m%n)<0){f(m/n+1,n);printf("%c",number[m%n+n]);}
		else{f(m/n,n);printf("%c",number[m%n]);}
}}

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	f(m,n);
	return 0;
}