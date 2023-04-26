#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void did(char*s)
{  int i,l=strlen(s);
	int fl=0,fm=0,fs=0;
	for(i=0;i<l;i++)
	{    switch (s[i]) 
	  { case '{': fl=1;break;
		case '}': fl=0;break;
		case '[': fm=1;break;
		case ']': fm=0;break;
		case '(': fs=1;break;
		case ')': fs=0;break;
	  }  
		if((fl==1&&fm==0)||(fm==1&&fs==0)||(fs==1&&fl==0)) continue;
		else break;
	}
	if(i==l) printf("Yes\n");
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