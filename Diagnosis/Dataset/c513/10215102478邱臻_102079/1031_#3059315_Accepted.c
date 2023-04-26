#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmpa(const void*a, const void*b){
	long long int *p1,*p2;
	p1=(long long int*)a;p2=(long long int*)b;
	return *p1>*p2?1:-1;
}
int cmpd(const void*a, const void*b){
	long long int *p1,*p2;
	p1=(long long int*)a;p2=(long long int*)b;
	return *p1<*p2?1:-1;
}
int main(int argc, char *argv[]) {
	long long int t,i,j,min,n;
	long long int a[1001],b[1001]; 
	scanf("%lld",&t);
	for(i=0;i<t;i++){
		for(j=0;j<1001;j++){a[j]=0;b[j]=0;}  //初始化 
		min=0;
		scanf("%lld",&n);  //向量的维数
		for(j=0;j<n;j++)scanf("%lld",&a[j]);
		qsort(a,n,sizeof(a[0]),cmpa);  //升序排列 
		for(j=0;j<n;j++)scanf("%lld",&b[j]);
		qsort(b,n,sizeof(b[0]),cmpd);  //降序排列
		for(j=0;j<n;j++){
			min+=a[j]*b[j];
		}
		printf("case #%lld:\n%lld\n",i,min);
	} 
	return 0;
}