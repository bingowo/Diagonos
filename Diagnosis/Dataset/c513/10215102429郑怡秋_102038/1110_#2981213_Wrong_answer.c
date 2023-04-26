#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
	char ind[100];
	scanf("%s",ind);
	double x=.0;//未知量系数
	double y=.0;//常数
	char c;//未知量
	int l=strlen(ind),k;
	for(int i=0;i<l;i++)
	{
		if(isalpha(ind[i])) 
		{
			c=ind[i];
		}
		if(ind[i]=='=') k=i;
	} //printf("k:%d\n",k);
	int an=0,d=0,sign=1;
	if(ind[d]=='-') sign=-1,d++;
	else if(ind[d]=='+') d++;
	while(d<=k)
	{
		an=0;
		while(isdigit(ind[d]))
		{
			an=an*10+ind[d++]-'0';
		}
		if(ind[d]==c)
		{
			if(an==0) x+=sign*1;
			else x+=sign*an;
		}
		if(ind[d]=='-')
		{
			y+=sign*an;//printf("y:%f\n",y);
			sign=-1;
		}
		else if(ind[d]=='+')
		{
			y+=sign*an;//printf("y:%f\n",y);
			sign=1;
		}
		else if(ind[d]=='='&&isdigit(ind[d-1]))
		{
			y+=sign*an;
		}
		d++;
	}
	d=k+1;sign=1;
	if(ind[d]=='-') d++;
	else if(ind[d]=='+') sign=-1,d++;
	while(d<=l)
	{
		an=0;
//		if(d==l)
//		{
//			y=sign*an;
//		}
		while(isdigit(ind[d]))
		{
			an=an*10+ind[d++]-'0';
		}
		if(ind[d]==c)
		{
			if(an==0) x+=sign*1;
			else x+=sign*an;
		}
		if(ind[d]=='-')
		{
			y+=sign*an;//printf("y:%f\n",y);
			sign=1;
		}
		else if(ind[d]=='+')
		{
			y+=sign*an;//printf("y:%f\n",y);
			sign=-1;
		}
		else if(d>=l&&isdigit(ind[d-1]))
		{
			y+=sign*an;
		}
		d++;//printf("%f %c %f\n",x,c,y);
	}if(y!=0) y=-y;
	printf("%c=%.3f\n",c,y/x);
	return 0; 
}