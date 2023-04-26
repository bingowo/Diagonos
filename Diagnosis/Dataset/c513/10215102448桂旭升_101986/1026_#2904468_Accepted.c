#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int n[100000] = {0};
int cmp(const void *a, const void *b){
    int i = 0; int *pa = (int *)a, *pb = (int *)b;//printf("%c %c\n", ca, cb);
	return *pb-*pa;
}

int main(){
	int i = 0, num = 0;
	long long res = 0;
	scanf("%d", &num);
	for(i = 0; i < num; i++){
		scanf("%d", &n[i]);
	}
	qsort(n, num, sizeof(int), cmp);
	for(i = 0; i < num; i += 2){
		res += (n[i] - n[i+1]);
	}
	printf("%lld", res);
	//if(A[j].t != 1)printf("%d", A[j].real);
}