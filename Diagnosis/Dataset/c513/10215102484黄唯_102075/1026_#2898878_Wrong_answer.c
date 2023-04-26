#include<stdio.h>
//按从小到大排序的结果就是最小的
// creat on 2022/3/5 

typedef long long int lli;
 
lli llabs(lli x){
	return x < 0 ? -x : x ;
} 

int cmp(const void *a, const void *b){
	lli na = *(lli *)a;
	lli nb = *(lli *)b;
	return na > nb ? 1 : -1; 
}

int main(void){
	int n;
	scanf("%d",&n);
	lli spot[n], mindistance = 0;
	for(int i = 0;i < n;i ++){
		scanf("%lld",&spot[i]);
		qsort(spot,n,sizeof(lli),cmp);
		
	}
	for(int i = 0;i < n;i += 2){
		mindistance += llabs(spot[i] - spot[i+1]);
	  
	 } 
	 printf("%lld",mindistance);
	 return 0;
}