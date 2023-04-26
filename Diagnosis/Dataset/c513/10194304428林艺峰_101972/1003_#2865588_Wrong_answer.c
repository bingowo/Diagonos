#include <stdio.h>
#include <stdlib.h>
struct num{
	long long value;
	int count;
}a[10010];
int complement(long long x){
	int flag = 0, count = 0;
	if(x < 0){
		flag = 1;
		x = ~x;
	}
	while(x){
		if(x % 2 == 1)	count++;
		x = x / 2;
	}
	if(flag)	count = 64 - count;
	return count;
}
int cmp(struct num x, struct num y){
	if(x.count != y.count){
		if(x.count > y.count)	return -1;
		else return 1;
	}
	else{
		if(x.value < y.value)	return -1;
		else return 1;
	}
}
int main(){
	int t, n, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d", &n);
		for(j = 0; j < n; ++j){
			scanf("%lld", &a[j].value);
			a[j].count = complement(a[j].value);
		}
		qsort(a, n, sizeof(a[0]), cmp);
		printf("case #%d:\n",i);
		for(j = 0; j < n; ++j)	printf("%lld ",a[j].value);
		printf("\n");
	}
	return 0;
}