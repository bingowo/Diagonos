#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
#define MAX 100001
int main()
{
	char s[MAX];
	scanf("%s",s);
	int len=strlen(s);
	int l=0,a=0,b=1,k=0;
	if(len==1) printf("%s\n",s);
	else if(len==2&&s[0]==s[1]) printf("%c\n",s[0]); 
	else
	{	int m1=a,m2=b;
		k=0;
		int i=1,j=0,a=0,b=0;
		int l,max;
		while(b<len)
		{
			//m1=a;m2=b;
			k=0;
			for(j=a;j<b;j++)
			{
				if(s[b]==s[j])
				{
					k=1;break;
				}
			}
			if(k==1) 
			{
				if(b-a>m2-m1) m2=b,m1=a;
				a++;b=a+1;
			}
			else if(k==0)
			{
				b++;
				if(b-a>m2-m1) m2=b,m1=a;
			}
			
		}
		for(int j=m1;j<m2;j++) printf("%c",s[j]); 
	}
	
	return 0;
} 