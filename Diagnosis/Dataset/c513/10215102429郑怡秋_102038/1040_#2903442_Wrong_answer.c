#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>


int main()
{
	char m[15],f[15],c[15];
	scanf("%s%s%s",m,f,c);
	char ans[15][3];
	char m1,m2,f1,f2;
	if(m[0]=='?') 
	{
		int l=strlen(f);
		if(l==2)
		{
			if(c[0]=='O')
			{
				printf("impossible");
				printf(" %s %s\n",f,c);
			}
			else if(strlen(c)==1&&c[0]=='A')
			{
				printf("{A,O}");
				printf(" %s %s\n",f,c);
			}
			else if(strlen(c)==1&&c[0]=='B')
			{
				printf("{B,O}");
				printf(" %s %s\n",f,c);
			}
			else 
			{
				printf("{A,AB,B,O}");
				printf(" %s %s\n",f,c);
			}
		}
		else if(l==1) 
		{
			if(f[0]=='O'&&c[0]=='O') printf("{O} O O\n");
			else if(strlen(c)==1&&f[0]!=c[0])
			{
				if(c[0]=='A'&&f[0]=='O') printf("{A,AB} %s %s\n",f,c);
				else if(c[0]=='B'&&f[0]=='O') printf("{AB,B} %s %s\n",f,c);
				else if(c[0]=='A'&&f[0]=='B') printf("{A,AB} %s %s\n",f,c);
				else if(c[0]=='B'&&f[0]=='A') printf("{AB,B} %s %s\n",f,c);
			}
			else if(strlen(c)==2)
			{
				if(f[0]=='A') printf("{AB,B} %s %s\n",f,c);
				else if(f[0]=='B') printf("{A,AB} %s %s\n",f,c);
			}
		}
		
	}
	else if(f[0]=='?')
	{
		int l=strlen(m);
		if(l==2)
		{
			if(c[0]=='O')
			{
				printf("%s impossible %s\n",m,c);
			}
			else if(strlen(c)==1&&c[0]=='A')
			{
				printf("%s {A,O} %s\n",f,c);
			}
			else if(strlen(c)==1&&c[0]=='B')
			{
				printf(" %s {B,O} %s\n",m,c);
			}
			else 
			{
				printf("%s {A,AB,B,O} %s\n",f,c);
			}
		}
		else if(l==1) 
		{
			if(f[0]=='O'&&c[0]=='O') printf("{O} O O\n");
			else if(strlen(c)==1&&f[0]!=c[0])
			{
				if(c[0]=='A'&&f[0]=='O') printf("{A,AB} %s %s\n",f,c);
				else if(c[0]=='B'&&f[0]=='O') printf("{AB,B} %s %s\n",f,c);
				else if(c[0]=='A'&&f[0]=='B') printf("{A,AB} %s %s\n",f,c);
				else if(c[0]=='B'&&f[0]=='A') printf("{AB,B} %s %s\n",f,c);
			}
			else if(strlen(c)==2)
			{
				if(f[0]=='A') printf("{AB,B} %s %s\n",f,c);
				else if(f[0]=='B') printf("{A,AB} %s %s\n",f,c);
			}
		}
		
	}
	else if(c[0]=='?');
	
	return 0;
}