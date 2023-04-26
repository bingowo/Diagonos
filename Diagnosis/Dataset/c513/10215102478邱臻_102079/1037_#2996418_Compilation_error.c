#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void*a,const void*b){
	long long int *p1,*p2;
	p1=(long long int*)a;p2=(long long int*)b;
	return *p1>*p2?-1:1;  //倒序排列 
}
int main(int argc, char *argv[]) {
	long long int n,m,result,min,i,j;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lld",&number[i]);  //输入N个整数
	}
	min=0;result=0;
	qsort(number,n,sizeof(number[0]),cmp);  //从大到小排序
	for(i=0;i<n-m;i++){
		for(j=0;j<m;j++){
			result+=number[i+j]-number[i+j+1];
		}
		min=min>result?result:min;  //保存最小值 
		result=0;
	}
	printf("%lld",min); 
	return 0;
}