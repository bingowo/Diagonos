#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int time;
void cal(char*s)
{
	int l=strlen(s),i,j;
	for(i=0,j=l-1;i<j;i++,j--)
	{
		if(s[i]!=s[j])
		{   time++;
			break;
		}
	}
	if(i>=j)
	{
	     printf("%d %s",time,s);	
	}
	else 
	{
        int a=atoi(s),k,b=0,c,m=0;
      	for(k=l-1;k>=0;k--) b=b*10+s[k];
	  	c=a+b;
	  	while(c!=0)
	  	{  int t=c%10;
	  		s[m++]='0'+t;
	  		c=c/10;
		  }
		  s[m]='\0';
		cal(s);
	}
}
int main()
{    char s[1000]={'\0'};
	scanf("%s",s);
	cal(s);
	return 0;
}