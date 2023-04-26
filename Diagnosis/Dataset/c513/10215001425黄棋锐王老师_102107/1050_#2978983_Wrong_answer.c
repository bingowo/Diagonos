#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXTOKEN 100
 #define NUMBER '0'
 int max(int a,int b)
 {return (a-b)?a:b;
 }
 int sleft(char*s,char*s1)
 {
 	int i,j,sl=strlen(s),s1l=strlen(s1);
 	for(i=0;i<sl-s1l;i++)
 	{for(j=0;j<s1l&&s[i+j]==s1[j];j++);
 		if(j==s1l) return i;
	 }
	 return -1;
 }
 int sright(char*s,char*s1)
 {
 	int i,j,sl=strlen(s),s1l=strlen(s1);
 	for(i=sl-s1l;i>=0;i--)
 	{for(j=0;j<s1l&&s[i+j]==s1[j];j++);
 		if(j==s1l) return i;
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
 		l=sleft(s,s1);
 		r=sright(s,s2);
 		if(r!=-1&&l!=-1)
		{
 		d=max(d,r-l-strlen(s1));
 		r=sright(s,s1);
 		l=sleft(s,s2);
 		d=max(d,r-l-strlen(s2));
 	    }
 	    printf("case #%d:\n",k);
 		printf("%d\n",d);
	 }
	 	
 	return 0;
 }

