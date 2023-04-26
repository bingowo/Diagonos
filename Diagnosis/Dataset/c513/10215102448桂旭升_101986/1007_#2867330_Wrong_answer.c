#include<stdio.h>
#include<string.h>
int B[50];
int biggest(int a[], int wei){
	int i, max = a[0];
	for(i = 0; i < 50; i++){
		
		if(a[i] > max)max = a[i];
	}
	if(max == 0)max = wei;
	return max;
}
int f(long long n){
	int num = 1, res = 0, y = 0, last = 0, j, i = 0, wei = 0;
	for(j = 0; j < 50; j++){
		B[j] = 0;
	}
	y = n % 2;last = y;
	n = n / 2;wei++;
	while(n > 0){
		y = n % 2;
		if(y != last){
			num++;
			last = y;
		}
		else{
			last = y;
			B[i] = num;i++;
			num = 1;
		}
		n = n / 2;
		wei++;
	}
	return biggest(B, wei);
}

int main()
{
	int t, i;long long n;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%lld", &n);
		printf("case #%d:\n", i);
		printf("%d", f(n));
		printf("\n");
	}
	return 0;
}