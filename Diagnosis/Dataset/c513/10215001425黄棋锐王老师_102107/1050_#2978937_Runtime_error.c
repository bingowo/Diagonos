#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXTOKEN 100
 #define NUMBER '0'
 int sright(char*s,char*s1)
 {
 	int i,j;
 	for(i=0;i<strlen(s)-strlen(s1);i++)
 	{for(j=0;j<strlen(s1)&&s[i+j]==s1[j];j++);
 		if(j==strlen(s1)) return i;
	 }
	 return -1;
 }
 int sleft(char*s,char*s2)
 {
 	int i,j;
 	for(i=strlen(s)-strlen(s2);i>=0;i--)
 	{for(j=0;j<strlen(s2)&&s[i+j]==s2[j];j++);
 		if(j==strlen(s2)) return i;
	 }
 	return -1;
 }
 int main()
 {
 	int k,T;
 	scanf("%d\n",&T);
 	for(k=0;k<T;k++)
 	{	char s1[82]={'\0'};
 	    char s2[82]={'\0'};
 	    char s[82]={'\0'};
 	    int l=0,r=0,d=0;
	    scanf("%s",s1);//gets(s1);gets(s2);gets(s);
 		scanf("%s",s2);
 		scanf("%s",s);
 		if(sright(s,s1)!=-1&&sleft(s,s2)!=-1)
		{
		r=sright(s,s1);
 		l=sleft(s,s2);
 		d=l-r-strlen(s1);
 		r=sright(s,s2);
 		l=sleft(s,s1);
 		d=(d>(l-r-strlen(s2)))?d:l-r-strlen(s2);
 	    }
 	    else d=0;
 	    printf("case #%d:\n",k);
 		printf("%d\n",d);
	 }
	 	
 	return 0;
 }

