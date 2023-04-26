#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void*a,const void*b){
	long long int *p1,*p2;
	p1=(long long int*)a,p2=(long long int*)b;
	return *p1>*p2?-1:1;
}
int main() {
	long long int n,count=0,i;
	long long int list[100005]={};
	scanf("%lld",&n);
	for(i=0;i<n;i++)scanf("%lld",&list[i]);
	qsort(list,n,sizeof(list[0]),cmp);
	for(i=0;i<n-1;i+=2){
		count+=(list[i]-list[i+1]);
	}
	printf("%lld",count);
	return 0;
}