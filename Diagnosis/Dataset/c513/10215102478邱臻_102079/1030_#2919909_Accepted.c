#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long int max(long long int x){
	long long int y;
	while(x/10!=0){
		x=x/10;
	} 
	y=x;
	if(y<0)y=-y;
	return y;
}
int cmp(const void* a,const void* b){
	long long int *p1,*p2;
	p1=*(long long int(*)[2])a;p2=*(long long int(*)[2])b;
	if(*(p1+1)!=*(p2+1))return *(p1+1)<*(p2+1)?1:-1;
	else return *p1<*p2?-1:1;
}
int main() {
	long long int t,i,j,z,n;
	long long int number[10000][2];
	scanf("%lld",&t);  //问题数量 
	for(i=0;i<t;i++){  //每组问题 
		scanf("%lld",&n);  //整数的数量 
		for(j=0;j<n;j++){
			scanf("%lld",&number[j][0]);  //数组记录整数 
			number[j][1]=max(number[j][0]);  //最大位置的数 
		}
		qsort(number,n,sizeof(number[0]),cmp);
		printf("case #%lld:\n",i);
		for(z=0;z<n;z++){
			printf("%lld",number[z][0]);
			if(z==n-1)printf("\n");
			else printf(" ");
		}
	} 
	return 0;
}