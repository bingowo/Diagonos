#include<stdio.h>
//递归寻找i能飞被算出 
int solve(int* w,int n,int i){
	if(i==0)
		return 1;
	if(n==0)
		return 0;
	int sign,x[3]={1,0,-1};
	for(int j=0;j<3;j++){
		sign=solve(w+1,n-1,i-x[j]*w[0]);
		if(sign==1)
			return 1;
	}
}
int main()
{
	int n,sum=0;
	scanf("%d",&n);
	int weight[10];
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
		sum+=weight[i];
	}
	for(int i=1;i<=sum;i++){
		printf("%d",solve(weight,n,i));
	}
	
	return 0;
}