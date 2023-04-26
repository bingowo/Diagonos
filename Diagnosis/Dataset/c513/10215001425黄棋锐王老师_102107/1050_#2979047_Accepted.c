#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int max(int x,int y)
{
	return x>y?x:y;
}
 int sleft(char*s,char*s1)
 {  char*p=strstr(s,s1);
     return (p==0)?-1:p-s;
 }
 int sright(char*s,char*s1)
 {
 	char*p=s,*p1=0;
 	while((p1=strstr(p,s1))!=0) p=p1+1;
 	return p-1-s;
 }
 int main()
 {
 	int k,T,d;
 	scanf("%d\n",&T);
 	for(k=0;k<T;k++)
 	{	char s1[82]={'\0'};
 	    char s2[82]={'\0'};
 	    char s[82]={'\0'};
 	    int l=0,r=0;
 	    d=0;
	    gets(s1);gets(s2);gets(s);
 		r=sright(s,s2);
 		l=sleft(s,s1);
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