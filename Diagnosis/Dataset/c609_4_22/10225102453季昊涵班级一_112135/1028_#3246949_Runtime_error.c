#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	int *A=*((int **)a);
	int *B=*((int **)b);
	int i=0;
	while(A[i]!=-1&&B[i]!=-1){
		if(A[i]>B[i])
		return 1;
		else if(A[i]<B[i])
		return -1;
		else
		i++;
	}
	if(A[i]==-1)
	return -1;
	if(B[i]==-1)
	return 1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int arr[n][50];
		int a;
		for(int k=0;k<n;k++){
			int l=0;
			while(scanf("%d",&a)!=EOF&&a!=-1){
				arr[k][l++]=a;
			}
			arr[k][l]=-1;
		}
		qsort(arr,n,sizeof(arr[0]),cmp);
		for(int i=0;i<n;i++){
			int j=0;
			while(arr[i][j]!=-1){
				printf("%d ",arr[i][j]);
				j++;
			}
			printf("\n");
		}
	}
	printf("\n");
	return 0; 
} 