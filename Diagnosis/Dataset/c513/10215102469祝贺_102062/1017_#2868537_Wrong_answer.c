#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int table[256];
char s[1000];
int p=0;
	
long long trans()
{
	long long ans=0;
	while(s[p]!=0)
	{
		switch(s[p])
		{
			case('V'):
			case('L'):
			case('D'):
			case('M'):
			{
				ans+=table[s[p++]];
				break;
			}
			
			case('I'):
			{
				p++;
				if(s[p]=='V' || s[p]=='X')
				{
					ans+=-table['I']+table[s[p++]];
				}
				else
				{
					ans+=table['I'];
				}
				break;
			}
			case('X'):
			{
				p++;
				if(s[p]=='L' || s[p]=='C')
				{
					ans+=-table['X']+table[s[p++]];
				}
				else
				{
					ans+=table['X'];
				}
				break; 
			}
			case('C'):
			{
				p++;
				if(s[p+1]=='D' || s[p]=='M')
				{
					ans+=-table['C']+table[s[p++]];
				}
				else
				{
					ans+=table['C'];
				}
				break;
			}
			case('('):
			{
				p++;
				ans+=trans();
				break;
			}
			case(')'):
			{
				p++;
				return ans*1000;
				break;
			}
			default:
				break;
		}
	}
	return ans;
}
int main()
{
	table['I']=1;table['V']=5;table['X']=10;
	table['L']=50;table['C']=100;table['D']=500;
	table['M']=1000;

	scanf("%s",s);
	printf("%lld",trans());
	return 0;
}