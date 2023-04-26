#include <stdio.h>
#include <stdlib.h>
typedef long long int lli;

int cmp(const void *a, const void *b)
{
	lli na = *(lli *)a;
	lli nb = *(lli *)b;
	return nb > na ? 1 : -1;
}

int main(void)
{
	int n, m;
	lli MinMinus = 0x3f;
	scanf("%d %d", &n, &m);
	lli in[n];
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld", &in[i]);
	}
	qsort(in, n, sizeof(lli), cmp);
	for(int i = 0 ; i < n - m + 1 ; i ++){
		lli temp = 0;
		for(int j = i + 1; j < i + m; j ++){
			temp += (in[i] - in[j]);
		}
		if(temp < MinMinus){
			MinMinus = temp;
		}
	}
	printf("%lld", MinMinus);
	
	return 0;
} 