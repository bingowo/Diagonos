#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int h(int x)
{
	int ans=1;
	while(x)
	{
		ans*=10;x--;
	}
	return ans;
}
int g(int x)
{
	char s[15];int i=0;
	while(x)
	{
		s[i++]=x%10+'0';
		x/=10;
	}int l=strlen(s);//printf("g :%s\n",s);
	int ans=0;
	for(int j=0;j<l;j++)
	{
		ans=ans*10+(s[j]-'0');
	}
	return ans;
}
int f(int x)
{
	char s[15];int i=0;
	while(x)
	{
		s[i++]=x%10+'0';
		x/=10;
	}
	int l=strlen(s);//printf("f :%s\n",s);
	for(int j=0;j<l/2;j++)
	{
		if(s[j]!=s[l-1-j]) return -1;
	}
	return 1;
}
int main()
{
	int x;
	scanf("%d",&x);
	int num=0;
	while(f(x)==-1)
	{
		x+=g(x);
		num++;
	}
	printf("%d %d",num,x);
}