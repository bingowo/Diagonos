#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void* a, const void* b)
{ return *(char*)a - *(char*)b; }
int main()
{
	int t;
	scanf("%d",&t);
	for(int k=0;k<t;k++)
	{
		char s[22]={'0'}; int i, j, x='9'+1, xi,y;
   		scanf("%s",s+1);
   		for (i=strlen(s)-1; s[i-1]>=s[i]; i--);  y=s[i-1];
   		for (j=strlen(s)-1; j>=i; j--)
       		if (s[j]>y && s[j]<x) {x=s[j], xi=j;}
   		s[i-1]=x; s[xi]=y;
   		qsort(s+i,strlen(s)-i,sizeof(s[0]),cmp);
   		printf("case #%d:\n",k);
   		printf("%s\n", s+(s[0]=='0'));
	}
	
}
