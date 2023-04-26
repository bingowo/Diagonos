#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
char s1[105],s2[105];
int co1[100],co2[100],ans[500]; 
void read(char *s, int* co)
{  
	while (*s)
   	{  
		int sign=1,coef=0,dim=0;
    	if (*s=='+' ) 
			s++;
  		else if (*s=='-') 
		  	sign=-1,s++;
    	while (isdigit(*s)) 
		{  
			coef=coef*10+*s-'0'; 
			s++; 
		}
    	if (coef==0) 
			coef=1;
    	if (*s!='x') 
		{ 
			co[0]=coef*sign; 
			return; 
		} 
		else 
			s++;
    	if (*s=='^') 
			s++;
    	while (isdigit(*s)) 
		{  
			dim=dim*10+*s-'0'; 
			s++; 
		}
    	if (dim==0) 
			dim=1;
    	co[dim]=coef*sign;
    }
}
int main()
{
	while(scanf("%s%s",s1,s2)==2)
   	{  
   		read(s1,co1);read(s2,co2);
   		for (int i=0;i<50;i++)
     	for (int j=0;j<50;j++)
        ans[i+j]+=co1[i]*co2[j];
    	int flag=0;
  		for (int i=99;i>=0;i--)
  		{
		   	if (ans[i])
    		{
      			flag?printf(" %d",ans[i]):printf("%d",ans[i]);
      			flag=1;
    		}
  		}
  		printf("\n");
    	memset(s1,0,105);memset(s2,0,105);
    	memset(co1,0,100);memset(co2,0,105);memset(ans,0,105);
    }
	return 0;
}