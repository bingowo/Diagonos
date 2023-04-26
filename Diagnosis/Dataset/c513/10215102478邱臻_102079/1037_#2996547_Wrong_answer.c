#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void*a,const void*b){
	long long int *p1,*p2;
	p1=(long long int*)a;p2=(long long int*)b;
	return *p1>*p2?-1:1;  //倒序排列 
}
int main(int argc, char *argv[]) {
	long long int n,m,result,min,i,j,k;
	long long int number[101]={},minus[101]={};
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)scanf("%lld",&number[i]);  //输入N个整数
	min=0;result=0;
	qsort(number,n,sizeof(number[0]),cmp);  //从大到小排序
	for(i=0;i<n-1;i++)minus[i]=number[i]-number[i+1];  //记录两两之间的差值
	for(j=0;j<m-1;j++){
		for(k=j;k<m-1+j;k++){
			result+=minus[k]*(m-k-1+j);
		}
		if(j==0)min=result;
		else min=min<result?min:result;
		result=0;
	}
	printf("%lld",min); 
	return 0;
}