#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int d1[1000] = {0};
int d2[1000] = {0};
int cmpup(const void *a, const void *b){
    int i = 0; int *pa = (int *)a, *pb = (int *)b;//printf("%c %c\n", ca, cb);
    //if(*pa == *pb) *pb = 0;
	return *pa - *pb;
}
int cmpdown(const void *a, const void *b){
    int i = 0; int *pa = (int *)a, *pb = (int *)b;
    //if(*pa == *pb) *pb = 0;
	return *pb - *pa;
}

int main(){
	int t, n, i = 0, j;
	long long res = 0;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d", &n);
		for(j = 0; j < n; j++){
			scanf("%d", &d1[j]);
		}
		for(j = 0; j < n; j++){
			scanf("%d", &d2[j]);
		}
		qsort(d1, n, sizeof(int), cmpup);
		qsort(d2, n, sizeof(int), cmpdown);
		printf("case #%d:\n", i);
		for(j = 0; j < n; j++){
			res = res + d1[j]*d2[j];
		}
		printf("%lld\n", res);
		res = 0;
	}
}