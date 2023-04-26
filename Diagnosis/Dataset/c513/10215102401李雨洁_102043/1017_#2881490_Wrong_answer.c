#include<stdio.h>
#include<string.h>
int main()
{
	char s[50];
	int i,j,a[50]={0};
	int number=0;
	while(scanf("%s",s) != EOF)
	{
		int c=0;
		int len = strlen(s);
		for(i=0;i<len;i++)
		{
		    if(s[i]=='(')
            {
                number++;
            }
			else if(s[i]=='M')
			{
				a[c]=1000;
				c++;
			}
			else if(s[i]=='C')
			{
				if(s[i+1]=='D')
				{
					a[c]=400;
					c++;
					s[i+1]='0';
				}
				else if(s[i+1]=='M')
				{
					a[c]  =900;
					c++;
					s[i+1]='0';
				}
				else
				{
					a[c]=100;
					c++;
					s[i]='0';
				}
			}
			else if(s[i]=='X')
			{
				if(s[i+1]=='L')
				{
					a[c]=40;
					c++;
					s[i+1]='0';
				}
				else if(s[i+1]=='C')
				{
					a[c]=90;
					c++;
					s[i+1]='0';
				}
				else
				{
					a[c]=10;
					c++;
					s[i]='0';
				}
			}
			else if(s[i]=='I')
			{
				if(s[i+1]=='V')
				{
					a[c]=4;
					c++;
					s[i+1]='0';
				}
				else if(s[i+1]=='X')
				{
					a[c]=9;
					c++;
					s[i+1]='0';
				}
				else
				{
					a[c]=1;
					c++;
					s[i]='0';
				}
			}
			else if(s[i]=='V')
			{
				a[c]=5;
				c++;
			}
			else if(s[i]=='L')
			{
				a[c]=50;
				c++;
			}
			else if(s[i]=='D')
			{
				a[c]=500;
				c++;
			}
		}
		int end = 0;
		for(i=0;i<c;i++)
		{
			end+=a[i];
		}
		if(number!=0) printf("%d\n",end);
		else printf("%d\n",end*number*1000);
	}
 }
