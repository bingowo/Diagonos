#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b)
{
	char*p1=(char*)a;char*p2=(char*)b;
	int l1=strlen(p1),l2=strlen(p2);
	int i1=0,i2=0;
	int j1=0,j2=0;
	for(int j=0;j<l1;j++) {if(isdigit(p1[j])) i1=i1*10+(p1[j]-'0'),j1+=1;}
	for(int j=0;j<l2;j++) {if(isdigit(p2[j])) i2=i2*10+(p2[j]-'0'),j2+=1;}
	//printf("%d %d\n",i1,i2);
	if(j1>0&&j2==0) return 1;
	else if(j1==0&&j2>0) return -1;
	else if((j1==0&&j2==0) || i1==i2) 
	{
		if(strcmp(p1,p2)>0) return 1;
		else return -1;
	}
	else if(j1>0&&j2>0) 
	{
		if(i1>i2) return 1;
		else return -1;
	}
	
	
}


int main()
{
	char A[110][35];
	int i=0;
	while(scanf("%s",A[i])!=EOF) i++;
	//for(int j=0;j<i;j++) printf("%s\n",A[j]);
	qsort(A,i,sizeof(A[0]),cmp);
	for(int j=0;j<i-1;j++) printf("%s ",A[j]);
	printf("%s\n",A[i-1]);
	return 0;
}