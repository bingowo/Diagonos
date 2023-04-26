#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
unsigned int f(char c)
{   unsigned int i;
	if('0'<=c&&c<='9') i=c-'0';
	else if('a'<=c&&c<='f') i=c-'a'+10;
	return i;
}
int main()
{  char s[1000000]={'\0'};
	gets(s);
	int flag=0;
	int e=-1,i;
	unsigned int n=0;
	for(i=2;i<strlen(s);i++)
	{   if(s[i-2]=='0'&&s[i-1]=='x'&&(('0'<=s[i]&&s[i]<='9')||('a'<=s[i]&&s[i]<='f')))
	 {    flag=1;
	  for(;('0'<=s[i]&&s[i]<='9')||('a'<=s[i]&&s[i]<='f');i++)
	 		n=n*16+f(s[i]);
	 }
	 if(flag==1) 
	  {     e=1;
	  		flag=0;
	       printf("%u ",n);
	       n=0;
	   }
	}
	if(e==-1) printf("-1");
	return 0;
}