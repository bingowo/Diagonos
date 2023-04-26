#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int trans(char str1[])
{
	int len1,sum1=0,c=0;
	len1=strlen(str1)-1;
	for(len1;len1>=0;len1--)
	{
		if(str1[len1]>='a'&&str1[len1]<='f') 
			sum1=sum1+((str1[len1]-'a')+10)*pow(16,c);
		else sum1=sum1+(str1[len1]-'0')*pow(16,c);
		c++;
	}
//	printf("%d\n",str1[0]-'a'+10); 
	return sum1;
}

int main()
{
	char str[100000],str1[10000][10000];
	scanf("%s",str);
	int i=0,len,h=0,li=0,n=0;
	len=strlen(str);
	while(i<len-1)
	{
		if(str[i]=='0'&&str[i+1]=='x')
		{
			i=i+2;
			while((str[i]>='0'&&str[i]<='9')||(str[i]>='a'&&str[i]<='f'))
			{
				str1[h][li++]=str[i];
				i++;
			}
			n++;
			h++;
		}
		i++;
	}
//	printf("%d\n",h);
	
	int hh=0;
	if(n==0) printf("-1\n");
	else{
		for(hh;hh<h;hh++) printf("%d ",trans(str1[hh]));
		
	}
	return 0;
	
}