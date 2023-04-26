#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct N{
	long long num;
	int highest;
}a[10010];
int cmp(const void *a, const void *b){
	const struct N *pa = a, *pb = b;
	if((*pa).highest > (*pb).highest)	return -1;
	else if((*pa).highest < (*pb).highest)	return 1;
	else{
		if((*pa).num > (*pb).num)	return 1;
		else return -1;
	}
}
int main(){
	int t, n, i, j;
	scanf("%d", &t);
	long long num0 = 0;
	for(i = 0; i < t; ++i){
		scanf("%d", &n);
		for(j = 0; j < n; ++j){
			scanf("%lld", &a[j].num);
			num0 = a[j].num;
			if(num0 < 0)	num0 = -num0;
			while(num0 >= 10){
				num0 /= 10;
			}
			a[j].highest = num0;
		}
		qsort(a, n, sizeof(a[0]), cmp);
		printf("case #%d:\n", i);
		for(j = 0; j < n; ++j)	printf("%lld ", a[j].num);
		printf("\n");
	}
	return 0;
}