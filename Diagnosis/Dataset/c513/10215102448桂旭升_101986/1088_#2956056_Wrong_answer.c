#include<stdio.h>
int main(){
	int t, i, ans;
	double n, m, temp = 1;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%lf%lf", &m, &n);
		printf("case #%d:\n", i);
		if(n == 0)printf("1");
		else{
			for(int j = 0; j < n; j++){
				temp *= ((m-j)/(n-j));
			}
			printf("%lld", (long long)temp);
		}
		if(i != n-1)printf("\n");
	}
}