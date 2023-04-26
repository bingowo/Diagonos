#include<stdio.h>
#include<stdlib.h>
int A[1001];
int cmp(const void*p1,const void*p2){
	int a = *((int*)p1);
	int b = *((int*)p2);
	if(A[a]==0&&A[b]==0)
		return a-b;
	else{
		if(A[a]==0)
			return 1;
		if(A[b]==0)
			return -1;
		else
			return A[a] - A[b];
	}
}

int main()
{
	int m,n,a;
	int B[500];
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&a);
		A[a] = i+1;
	}	
	scanf("%d",&n);	
	for(int i=0;i<n;i++)
		scanf("%d",&B[i]);
	qsort(B,n,sizeof(int),cmp);
	for(int i=0;i<n;i++){
		printf("%d%c",B[i],i==n-1?'\n':' ');
	}
	return 0;
}