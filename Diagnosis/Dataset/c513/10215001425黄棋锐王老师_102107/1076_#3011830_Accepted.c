#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void did(char*s)
{  int i,l=strlen(s),j=0;
	char stack[100]={'\0'};
	int flag=1;
	for(i=0;i<l;i++)
	{    
	if(strlen(stack)==0) 
	{
	stack[j++]=s[i];
	continue;}				
	switch (s[i]) 
	  { case '{': 
	  if(stack[j-1]=='(') stack[j++]=s[i];
	   else 
	   {
	   	flag=0;goto FLAG;
	   }
	   break;
		case '}':
		if(stack[j-1]=='{') stack[j-1]='\0',j--;
	   else 
	   {
	   	flag=0;goto FLAG;
	   }	
		 break;
		case '[': 
		if(stack[j-1]=='{') stack[j++]=s[i];
	   else 
	   {
	   	flag=0;goto FLAG;
	   }	
		 break;
		case ']': 
		if(stack[j-1]=='[') stack[j-1]='\0',j--;
	   else 
	   {
	   	flag=0;goto FLAG;
	   }	
		 break;
		case '(': 
		 if(stack[j-1]=='[') stack[j++]=s[i];
	   else 
	   {
	   	flag=0;goto FLAG;
	   }
	   break;
		case ')': 
		if(stack[j-1]=='(') stack[j-1]='\0',j--;
	   else 
	   {
	   	flag=0;goto FLAG;
	   }	
		 break;
	  }  
		
	}
	FLAG:
	if(flag==1&&j==0) printf("Yes\n");
	else printf("No\n");
}
int main()
{   int k,T;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {  char s[102]={'\0'};
 	scanf("%s",s);
 	did(s);
 }
	return 0;
}