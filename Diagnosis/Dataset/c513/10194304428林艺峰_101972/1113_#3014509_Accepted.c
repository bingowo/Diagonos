#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct N{
	int num[110], len;
}a[110];
struct N sum;
int max(int a, int b){
	return a > b ? a : b;
}
void add(struct N *a, struct N *b){
	int l = max(a->len, b->len), i, temp = 0;
	for(i = 0; i < l; ++i){
		int c = ((a->num[i]) + (b->num[i]) + temp) / 10;
		a->num[i] = ((a->num[i]) + (b->num[i]) + temp) % 10;
		temp = c;
	}
	if(temp != 0){
		a->num[l] = temp;
		l += 1;
	}
	a->len = l;
}
int main(){
	int k, n, i, j;
	scanf("%d%d", &k, &n);
	a[1].num[0] = 0;
	a[1].len = 1;
	a[2].num[0] = 1;
	a[2].len = 1;
	for(i = 3; i <= n; ++i){
		memset(sum.num, 0, sizeof(sum.num));
		sum.len = 0;
		if(i > k){
			for(j = 1; j <= k; ++j){
				add(&sum, &a[i-j]);
			}
		}
		else if(i <= k){
			for(j = i - 1; j > 0; --j){
				add(&sum, &a[j]);
			}
		}
		a[i].len = sum.len;
		for(j = 0; j < sum.len; ++j){
			a[i].num[j] = sum.num[j];
		}
/*		for(j = a[i].len - 1; j >= 0; --j){
			printf("%d", a[i].num[j]);
		}
		printf("\n");*/
	}
	for(i = a[n].len - 1; i >= 0; --i){
		printf("%d", a[n].num[i]);
	}
	return 0;
}