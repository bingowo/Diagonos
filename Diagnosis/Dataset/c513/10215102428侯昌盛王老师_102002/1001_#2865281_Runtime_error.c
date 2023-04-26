#include <stdio.h>
#define M 100
char h(int m)
{
	return 'A'+(m-10);
}
void trans(int a,int b)
{
	char s[M];
	int i=0,m;
	while(a!=0)
	{
		if(a%b>=10)
		{
			m=a%b;
			s[i++]=h(m);
		}	
		else s[i++]=a%b;
		a/=b;
		
	}
	i-=1;
	for(i;i>=0;i--) printf("%c",s[i]);
	printf('\n');

	
}
int main()
{
	int n,r,t,i=0;
	scanf("%d",&t);
	while(~scanf("%d %d",&n,&r)) trans(n,r);
	return 0;
	
}