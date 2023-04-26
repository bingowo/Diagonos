#include <stdio.h>
#include <string.h>
int main()
{
	char s[100];
	scanf("%s",s);
	int i=0;
	long long a=0,b=0,c=1;
	for(;i<strlen(s);i++)
	{
		if(s[i]=='.') break;
		a=a*3;
		if(s[i]=='1') a+=1;
		if(s[i]=='2') a-=1;
	}
	i++;
	for(;i<strlen(s);i++)
	{
		b=b*3;
		if(s[i]=='2') b-=1;
		if(s[i]=='1') b+=1;
		c=c*3; 
	}
	if(a>0 && b<0)
	{
		a--;
		b=b+c;
	}
	if(a<0 && b>0) 
	{
		a++;
		b=c-b;
		if(a==0) b=-b;
	}
	
	if(b==0) printf("%lld\n",a);
	else{
		if(a!=0) printf("%lld ",a);
		printf("%lld %lld",b,c);
	}
	return 0;
	
}