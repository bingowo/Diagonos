#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
 
#define N 1111
#define INF 1000009

int gcd(int a, int b){
	return b == 0 ? a :gcd(b, a%b);
} 

int cmpfunc(const void *a,const void *b) {
	return (*(int*)a - *(int*)b);
}

void solve(){
	int n, s;
	int a[N];
	scanf("%d %d",&n, &s);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a, n, sizeof(int), cmpfunc);
	a[n] = INF;
	int ans_int, ans_fz, ans_fm;
	for(int i = 1;i<=n;i++){
		int c = (a[i] - a[i-1]) * i;
		if(s < c){
			ans_int = a[i-1] + s/i;
			ans_fz = s % i;
			ans_fm = i;
			break;
		}
		else {
			s -= c;
		}
	}
	int g = gcd(ans_fz, ans_fm);
	ans_fz /= g;
	ans_fm /= g;
	
	if(ans_int == 0 && ans_fz > 0){
		printf("%d/%d",ans_fz, ans_fm);
	}
	else{
		printf("%d",ans_int);
		if (ans_fz > 0){
			printf("+%d/%d",ans_fz, ans_fm);
		}
	}
	printf("\n");
}
int main()
{
	solve();
	return 0;
}