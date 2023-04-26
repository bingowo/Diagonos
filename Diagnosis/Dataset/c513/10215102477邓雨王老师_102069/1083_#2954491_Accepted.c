#include<stdio.h>
int cal2(int n){ //求因数2的个数 
	int count=0;
	int temp=n; 
	while(temp%2==0){
		count++;
		temp/=2;
	}
	return count;
}
int cal5(int n){//求因数5的个数 
	int count=0;
	int temp=n;
	while(temp%5==0){
		count++;
		temp/=5;
	}
	return count;
}
int cal(int N){//求出1-N中2,5因数的总数，并返回较小的那个 
	int count1=0,count2=0,i;
	for(i=1;i<=N;i++){
		count1+=cal2(i);
		count2+=cal5(i);
	}
	return (count1>count2)?count2:count1; 
}
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		int n;
		scanf("%d",&n);
		printf("case #%d:\n",i);
		printf("%d\n",cal(n));
	}
}