#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void*a,const void*b){
	long long int *p1,*p2;
	p1=(long long int*)a;p2=(long long int*)b;
	return *p1>*p2?-1:1; 
}
int main() {
	long long int n,i,result=0;
	long long int number[10000];
	scanf("%lld",&n);
	for(i=0;i<n;i++)scanf("%lld",&number[i]);  //记录数字
	qsort(number,n,sizeof(number[0]),cmp);  //倒序排列 
	for(i=0;i<n;i+=2){
		result+=(number[i]-number[i+1]);
	}
	printf("%lld",result);
	return 0;
}