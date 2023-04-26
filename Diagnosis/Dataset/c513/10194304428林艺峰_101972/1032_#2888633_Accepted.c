#include<stdio.h>
#include<stdlib.h>
struct line{
	int num[60];
	int len;
}a[1010];
int cmp(const void *a, const void *b){
	const struct line *pa = a, *pb = b;
	int i;
	for(i = 0;(i < (*pa).len && i < (*pb).len); ++i){
		if((*pa).num[i] != (*pb).num[i])
			return (*pb).num[i] - (*pa).num[i];
	}
	return (*pb).num[i] - (*pa).num[i];
}
int main(){
	int t, n, l, i, j, k, num1;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d", &n);
		for(j = 0; j < n; ++j){
			l = 0;
			while(scanf("%d", &num1)){
				if(num1 == -1)	break;
				a[j].num[l++] = num1;
			}
			a[j].len = l;
		}
		qsort(a, n, sizeof(a[0]), cmp);
		for(j = 0; j < n; ++j){
			for(k = 0; k < a[j].len; ++k){
				printf("%d ", a[j].num[k]);
			}
			printf("\n");
		}
	}
	return 0;
}