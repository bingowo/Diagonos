#include<stdio.h>
#include<stdlib.h>
int a[1010];
int cmp(const void *a, const void *b){
	const int *pa = a, *pb = b;
	if((*pa) > (*pb))	return 1;
	return -1;
}
int gcd(int x, int y){
	if(x < y){	int c = x; x = y; y = c;}
	if(y == 0)	return x;
	return gcd(y, x % y);
}
int main(){
	int n, s, i, height, flag = -1;
	scanf("%d%d", &n, &s);
	for(i = 0; i < n; ++i)	scanf("%d", &a[i]);
	qsort(a, n, sizeof(a[0]), cmp);
	height = a[0];
	for(i = 1; i < n; ++i){
		if(s - (i + 1) * (a[i] - height) >= 0){
			s -= (i + 1) * (a[i] - height);
			height = a[i];
		}
		else{
			flag = i;
		}
	}
	if(flag == -1){
		while(s - n >= 0){
			s -= n;
			height += 1;
		}
		if(s == 0)	printf("%d", height);
		if(s != 0)	printf("%d+%d%d", height, s / gcd(s, n), n / gcd(s, n));
	}
	else{
		while(s - flag - 1 >= 0){
			s -= flag + 1;
			height += 1;
		}
		if(s == 0)	printf("%d", height);
		if(s != 0)	printf("%d+%d/%d", height, s / gcd(s, flag + 1), (flag + 1) / gcd(s, flag + 1));
	}
	return 0;
}