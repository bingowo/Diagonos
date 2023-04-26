#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int n;
char a[101];
double pol()
{
	//scanf("%[^' ','\n']",&a);
	scanf("%s",a);
	//printf("1");
	if(a[0]=='+')return pol()+pol();
	else if(a[0]=='-')return pol()-pol();
	else if(a[0]=='*')return pol()*pol();
	else if(a[0]=='/')return pol()/pol();
	else
	{
		n=strlen(a);
		double s=0,sig=0;int ch=1;
		for(int i=0;i<n;i++)
		{
			if(a[i]=='-')
			{
				ch=-1;continue;
			}
			if(a[i]=='.')
			{
				sig=0.1;continue;
			}
			if(sig==0)s=s*10.0+(double)(a[i]-'0');
			else
			{
				s+=(double)(a[i]-'0')*sig;
				sig*=0.1;
			}
		}
		if(ch==-1)s=-s;
		return s;
	}
}
int main()
{
	int t,cas=0;
	scanf("%d\n",&t);
	while(cas<t)
	{
		printf("case #%d:\n",cas++);
		printf("%.6lf\n",pol());
	}
	return 0;
}