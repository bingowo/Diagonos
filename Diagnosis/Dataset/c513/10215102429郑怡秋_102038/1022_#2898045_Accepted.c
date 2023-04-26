#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	char*p1=*((char**)a);char*p2=*((char**)b);
	int l1=strlen(p1),l2=strlen(p2);
	int i=0;	
	while(*(p1+i)!='@') i++;
	char *ind1=p1+i+1;
	i=0;
	while(*(p2+i)!='@') i++;
	char* ind2=p2+i+1;
	if(strcmp(ind1,ind2)==0) return -strcmp(p1,p2);
	else return strcmp(ind1,ind2);
	
}

int main()
{
	int n;
	scanf("%d",&n);
	char**A=(char**)malloc(n*sizeof(char*));
	char s[1000001],*p;
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		int len=strlen(s);
		p=(char*)malloc((len+1)*sizeof(char));
		strcpy(p,s);
		*(A+i)=p;
		
	}
	qsort(A,n,sizeof(A[0]),cmp);
	for(int i=0;i<n;i++) {printf("%s\n",A[i]);}
	for(int i=0;i<n;i++) {
		p=A[i];
		free(p);
	}
	return 0;
	
}