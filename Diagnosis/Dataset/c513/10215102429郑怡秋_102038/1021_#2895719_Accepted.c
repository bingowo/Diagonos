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
	//printf("k:%d\n",k);
	//printf("%s %s %s\n",p2->A,p1->B,p2->B);
	if(k==strlen(p1->B)) {return -1;}
	else if(k==strlen(p2->B)) return 1;
	else{
	for(i1=0;i1<26;i1++)
	{
		if(p1->B[k]==p1->A[i1]||p1->B[k]==(p1->A[i1]+32)) break;
	}
	for(i2=0;i2<26;i2++)
	{
		if(p2->B[k]==p2->A[i2]||p2->B[k]==(p2->A[i2]+32)) break;
	}
	//printf("%d %d\n",i1,i2);
	if(i1<i2) return -1;
	else return 1;
	}
}

int main()
{
	H *arr=(H*)malloc(100*sizeof(H));
	int ii=0;
	while(scanf("%s",arr[ii].A)!=EOF)
	{
		//printf("A:%s\n",arr[ii].A);
		int i=0;
		do{
			for(int j=0;j<26;j++) arr[i].A[j]=arr[ii].A[j];
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