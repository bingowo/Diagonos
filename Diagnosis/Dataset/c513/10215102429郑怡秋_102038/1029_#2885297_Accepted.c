#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h> 
int cmp(const void*a,const void*b)
{
	char* p1=(char*)a;
	char* p2=(char*)b;
	return *p1-*p2;
}
int main()
{
	int T;
	scanf("%d\n",&T);
	for(int i=0;i<T;i++)
	{
		char A[210];
		gets(A);
		char B[210];
		int l1=strlen(A),k=0;
		for(int j=0;j<l1;j++) {if(isalpha(A[j])) B[k++]=A[j];} 
		qsort(B,k,sizeof(B[0]),cmp);
		//printf("A: %s\n",A);
		int kk=0;
		for(int j=0;j<l1;j++)
		{
			if(isalpha(A[j])) A[j]=B[kk++];
		}
		printf("case #%d:\n",i);
		printf("%s\n",A);
	}
	return 0;
}