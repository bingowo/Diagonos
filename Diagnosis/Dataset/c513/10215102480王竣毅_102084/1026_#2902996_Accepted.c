
#include <stdio.h> 
#include <stdlib.h>

typedef long long int lli;

lli llabs(lli x){ return x < 0 ? -x : x;}

int cmp(const void *a, const void *b)
{
	lli na = *(lli *)a;
	lli nb = *(lli *)b;
	return na > nb ? 1 : -1 ;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	lli point[n], distance = 0;
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld", &point[i]);
	}
	qsort(point, n, sizeof(lli), cmp);
	for(int i = 0 ; i < n ; i += 2){
		distance += llabs(point[i] - point[i + 1]);
	}
	printf("%lld", distance);
	
	return 0;
}
