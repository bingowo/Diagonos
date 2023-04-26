#include <stdio.h>
#include <stdlib.h>

int gcd (int a, int b)
{
	int ret, rest = a % b;
	while(rest){
		a = b;
		b = rest;
		rest = a % b;
	}
	ret = b;
	return ret;
}

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int n;
		scanf("%d", &n);
		int a[n], map[1001] = {0}, idx = 0;
		for(int i = 0, t1 ; i < n ; i ++){
			scanf("%d", &t1);
			if(map[t1] == 0){
				a[idx ++] = t1;
				map[t1] = 1;
			}
		}
		qsort(a, idx, sizeof(int), cmp);
		int number = 0;
		for(int i = 0 ; i < idx - 1; i ++){
			for(int j = i + 1 ; j < idx; j ++){
				if(gcd(a[i], a[j]) == 1){
					number ++;
				}
			}
		}
		printf("case #%d:\n", i);
		printf("%d\n", number);
	}
	
	return 0;
}