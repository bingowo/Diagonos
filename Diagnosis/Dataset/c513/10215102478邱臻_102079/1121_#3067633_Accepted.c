#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int weight(int *a,int n,int target){
	int x[]={1,-1,0};
	int r=0,i;
	if(target==0)return 1;
	if(n==0)return 0;
	for(i=0;i<3;i++){
		r=weight(a+1,n-1,target+x[i]*a[0]);
		if(r==1)return 1;
	}
	return 0;
}
int main(int argc, char *argv[]) {
	int n,i,sum=0,target;
	int a[100]={};
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);sum+=a[i];
	}  //输入重量 
	for(target=1;target<=sum;target++){
		printf("%d",weight(a,n,target));
	}
	return 0;
}