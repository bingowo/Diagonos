#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp1(const void *p1, const void *p2);
int cmp2(const void *p1, const void *p2);
int A[500];
	
int main(void)
{
	int m;
    scanf("%d",&m);
	for(int i = 0; i < m; i++) scanf("%d",&A[i]);

	int n;
	scanf("%d",&n);
	int B[n],C[n];
	int temp = 0;
	int *find = A;
	int v = 0;
	int i = 0;
	for(int z = 0; z < n; z++){
		scanf("%d",&temp);
		while(*find != temp && (find - A) < m) find++;
		if((find - A) < m){
			C[v] = temp;
			v++;
		}
		else{
			B[i] = temp;
			i++;
		}
		find = A;
	}
	//printf("%d,%d ",v,i);

	qsort(B,i,sizeof(int),cmp1);
	qsort(C,v,sizeof(int),cmp2);

	for(int z = 0; z < v; z++) printf("%d ",C[z]);
	for(int z = 0; z < i; z++) printf("%d ",B[z]);
	
	return 0;
}

int cmp1(const void *p1, const void *p2)
{
	int a = *(int*)p1;
	int b = *(int*)p2;

	return a-b;
}
int cmp2(const void *p1, const void *p2)
{
	int a = *(int*)p1;
	int b = *(int*)p2;
	
	int *finda = A;
	while(*finda != a) finda++;
	int *findb = A;
	while(*findb != b) findb++;

	return finda - findb;
}