#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
unsigned long long int trans(char str1[])
{
	int c=0;
	unsigned long long len1,sum1;
	len1=strlen(str1)-1;
	for(len1;len1>=0;len1--)
	{
		if(str1[len1]>='a'&&str1[len1]<='f') 
			sum1=sum1+((str1[len1]-'a')+10)*pow(16,c);
		else sum1=sum1+(str1[len1]-'0')*pow(16,c);
		c++;
	}
	
	return sum1;
}

int main()
{
	char str[100000],str1[10000][10000];
	scanf("%s",str);
	int i=0,len,h=0,li=0,n=0,m=0;
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
				m++;
			//	printf("%c\n",s/r1[h][li-1]);
			//	printf("h=%d\n",h);
			}
		//	printf("%s\n",str1[h]);
			n++;
			if(m!=0){
				str1[h][li]='\0';
				h++;
				
			}
			m=0;
			li=0;
		}
		i++;
		m=0;
	}
//	printf("%d\n",h);
//	printf("%d\n",i);
	int hh=0;
	if(n==0) printf("-1\n");
	else{
		for(hh;hh<h;hh++) printf("%llu ",trans(str1[hh]));
		
	}
	return 0;
	
}