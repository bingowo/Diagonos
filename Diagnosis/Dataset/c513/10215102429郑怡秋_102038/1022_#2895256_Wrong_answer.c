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
	char a1[1000],a2[1000],b1[1000],b2[1000];	
	while(p1[j1]!='@') {a1[j1]=p1[j1];j1++;}
	a1[j1]='\0';
	i1=j1;j1++;
	for(int k=0;j1<l1;k++,j1++)	{a2[k]=p1[j1];}	
	a2[j1]='\0';
	while(p2[j2]!='@') {b1[j2]=p2[j2];j2++;}
	b1[j2]='\0';
	i2=j2;j2++;
	for(int k=0;j2<l2;k++,j2++)	{b2[k]=p2[j2];}	
	b2[j2]='\0';
	//printf("a1:%s\na2:%s\nb1:%s\nb2:%s\n",a1,a2,b1,b2);
	if(strcmp(a2,b2)>0) return 1;
	else if(strcmp(a2,b2)<0) return -1;
	else{
		if(strcmp(a1,b1)>0) return -1;
		else return 1;
	}
	
}

int main()
{
	int n;
	scanf("%d",&n);
	char A[1000][1000];
	for(int i=0;i<n;i++) {scanf("%s",A[i]);}
	qsort(A,n,sizeof(A[0]),cmp);
	for(int i=0;i<n;i++) {printf("%s\n",A[i]);}
	return 0;
	
}