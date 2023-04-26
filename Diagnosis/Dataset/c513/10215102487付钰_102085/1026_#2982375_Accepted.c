
#include <stdio.h> 
#include <stdlib.h>

long long int  llabs(long long int x)
   { return x < 0 ? -x : x;}

int cmp(const void *a, const void *b)
{
	long long int na = *(long long int *)a;
	long long int nb = *(long long int *)b;
	return na > nb ? 1 : -1 ;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	long long int point[n], distance = 0;
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld", &point[i]);
	}
	qsort(point, n, sizeof(long long int), cmp);
	for(int i = 0 ; i < n ; i += 2){
		distance += llabs(point[i+1] - point[i ]);
	}
	printf("%lld", distance);
	
	return 0;
}
