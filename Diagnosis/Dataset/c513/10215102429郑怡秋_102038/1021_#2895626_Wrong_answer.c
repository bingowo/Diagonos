#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct{
	char A[26];
	char B[25];
}H;
int cmp(const void*a,const void*b)
{
	H*p1=(H*)a;H*p2=(H*)b;
	int k=0;
	int i1,i2;
	while(p1->B[k]==p2->B[k]) k++;
	for(i1=0;i1<26;i1++)
	{
		if(p1->B[k]==p1->A[i1]||p1->B[k]==p1->A[i1]-32) break;
	}
	for(i2=0;i2<26;i2++)
	{
		if(p2->B[k]==p2->A[i2]||p2->B[k]==p2->A[i2]-32) break;
	}
	return i2-i1;
}

int main()
{
	H *arr=(H*)malloc(100*sizeof(H));
	int ii=0;
	while(scanf("%s",arr[ii].A)!=EOF)
	{
		int i=0;
		do{
			scanf("%s",arr[i++].B);
			//printf("%s ",B[i-1]);
		}while(getchar()!='\n');
		qsort(arr,i,sizeof(arr[0]),cmp);
		for(int j=0;j<i-1;j++) printf("%s ",arr[j].B);
		printf("%s\n",arr[i-1].B);
		ii++;
	}
	return 0;
 } 