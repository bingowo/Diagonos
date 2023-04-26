#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void did(char*s)
{  int i,l=strlen(s);
	int fl[100]={0},fm[100]={0},fs[100]={0};
	for(i=0;i<l-1;i++)
	{    switch (s[i]) 
	  { case '{': fl[i]=1;break;
		case '}': fl[i]=0;break;
		case '[': fm[i]=1;break;
		case ']': fm[i]=0;break;
		case '(': fs[i]=1;break;
		case ')': fs[i]=0;break;
	  }  
		if((fl[i]==1&&fs[i+1]==1)||(fm[i]==1&&fl[i+1]==1)||(fs[i]==1&&fm[i+1]==1)) break;
	}
	if(i==l-1) printf("Yes\n");
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