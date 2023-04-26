#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void add(char*s)
{     int l=strlen(s);
	  int a=0,k,b=0,c=0,m=0;
	  for(k=0;k<l;k++) a=a*10+s[k]-'0';
      for(k=l-1;k>=0;k--) b=b*10+s[k]-'0';
	  	c=a+b;
	  	while(c!=0)
	  	{  int t=c%10;
	  		s[m++]='0'+t;
	  		c=c/10;
		  }
		  s[m]='\0';
}
int cal(char*s,int time)
{   int l=strlen(s),i,j;
	for(i=0,j=l-1;i<j;i++,j--)
	{
		if(s[i]!=s[j])
		{   add(s);
		return cal(s,time+1);
		}
	}
	 return time;
	
}
int main()
{    char s[1000]={'\0'};
	scanf("%s",s);
	int t=cal(s,0);
	printf("%d %s",t,s);
	return 0;
}