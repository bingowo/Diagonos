#include<stdio.h>

int res[1010][1010] = {0};
int C(int n,int m){
	if(m == 0||m == n){
		return 1;
	}
	if(res[n][m] != 0){
		return res[n][m];
	}
	return res[n][m] = (C(n-1,m)+C(n-1,m-1)) % 10007;
}

int fac(int a, int n){
    int f[1000] = {1}; int len = 1;
    if (n < len) return f[n];
    for(; len <= n; len++) f[len] = f[len - 1] * a % 10007;
    return f[n];
}

int cal(int a, int b, int k, int m, int n){
    int com = C(k, m); 
    int fa = fac(a % 10007, m);
    int fb = fac(b % 10007, n);
    return ((com * fa) % 10007 * fb) % 10007;
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        printf("case #%d:\n", i);
        int a, b, k, n, m;
        scanf("%d%d%d%d%d", &a, &b, &k, &m, &n);
        printf("%d\n", cal(a, b, k, m, n));
    }
    return 0;
}