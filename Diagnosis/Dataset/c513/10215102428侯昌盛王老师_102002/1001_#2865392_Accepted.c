#include <stdio.h>
#include <math.h>
#define M 100
char h(int m)
{
	return 'A'+(m-10);
}
void trans(int a,int b)
{
	int s[M];
	int i=0,m,j,k;
	k=a;
	a=abs(a);
	while(a!=0)
	{
		s[i++]=a%b;
		a/=b;
		
	}
	j=i-1;
	if(k<0) printf("-");
	for(j;j>=0;j--)
	{
		if(s[j]>=0 && s[j]<10) printf("%d",s[j]);
		else if(s[j]>=10) printf("%c",h(s[j]));
		
	}
	printf("\n");

	
}
int main()
{
	int n,r,t,i=0;
	scanf("%d",&t);
	for(i;i<t;i++)
	{
		scanf("%d %d",&n,&r);
		trans(n,r);
	}
	return 0;
	
}