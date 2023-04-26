#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void* a,const void* b){
	long long int* p1,*p2;
	p1=(long long int*)a;p2=(long long int*)b;
	return *p1<*p2?-1:1;
}
int main(int argc, char *argv[]) {
	long long int n,i,number,result=0,j;
	long long int x[10000];
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&x[i]);
	}
	qsort(x,n,sizeof(x[0]),cmp);  //数组从小到大排序 
	for(j=0;j<n;j+=2){
		number=x[j]-x[j+1];
		number=number>0?number:-number;
		result+=number;
	}
	printf("%lld",result);
	return 0;
}