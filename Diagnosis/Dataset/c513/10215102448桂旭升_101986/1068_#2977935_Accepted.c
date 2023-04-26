#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 1000000007
char s[1001] = {'\0'};
long long RE(int n, int m)
{
    if(n < m) return 0;
    if(n == m) return 1;

    return 2 * RE(n - 1,m) + pow(2, n-m-1) - RE(n - m - 1,m);
}
	
int main(){ 
	int i = 0, n, m, len, t, j, k;
	double a;
	while(1){
		scanf("%d%d", &n, &m);
		if(n == -1 && m == -1)break;
		else{
			
			printf("%lld\n", RE(n, m));
		}
	}
	return 0;
}