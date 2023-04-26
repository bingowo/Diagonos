#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp1(const void*a,const void*b){
	long long int *p1,*p2;
	p1=(long long int*)a,p2=(long long int*)b;
	return *p1>=*p2?1:-1;
}
int cmp2(const void*a,const void*b){
	long long int *p1,*p2;
	p1=(long long int*)a,p2=(long long int*)b;
	return *p1>=*p2?-1:1;
}
int main() {
	long long int number[2][1001];
	long long int t,i,j,k,result,n;
	scanf("%lld",&t);
	for(i=0;i<t;i++){
		scanf("%lld",&n);
		result=0;
		for(j=0;j<2;j++){
			for(k=0;k<1001;k++)number[j][k]=0;
		}
		for(j=0;j<2;j++){
			for(k=0;k<n;k++){
				scanf("%lld",&number[j][k]);
			}
			if(j==0){
				qsort(number[j],n,sizeof(number[j][0]),cmp1);
			}
			else{
				qsort(number[j],n,sizeof(number[j][0]),cmp2);
			}
		}   //输入向量
		printf("case #%lld:\n",i);
		for(k=0;k<n;k++)result+=number[0][k]*number[1][k];
		printf("%lld\n",result);
	}
	return 0;
}