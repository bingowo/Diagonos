
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
	scanf("%d %d", &n, &m);
	lli in[n];
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld", &in[i]);
	}
	qsort(in, n, sizeof(lli), cmp);
	lli temp = 0;
	for(int i = 1; i < m; i ++){
		temp += in[0] - in[i];
	}
	lli MinMinus = temp;
	for(int i = 1 ; i < n - m + 1 ; i ++){
		temp = temp - ((m - 1) * in[i - 1]) + (m * in[i]) - in[i + m - 1];

		if(temp < MinMinus){
			MinMinus = temp;
		}

	}
	printf("%lld", MinMinus);
	
	return 0;
} 
