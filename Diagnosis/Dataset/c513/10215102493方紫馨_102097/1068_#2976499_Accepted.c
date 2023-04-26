#include <stdio.h>
#include <math.h>
long long ret[32][32];
int main()
{
	int n, m;		
	for(int i = 0; i < 32; i ++){
		ret[i][i] = 1;
	}
	for(int i = 1; i < 32; i ++){
		for(int j = 1; j < i; j ++){
				ret[i][j] = 2 * ret[i - 1][j] + ret[i - j - 1][1] - ret[i - j - 1][j] + 1;					
		}
	}
	while(scanf("%d %d", &n, &m)&&n != -1 && m != -1){
		printf("%lld\n", ret[n][m]);
	}
	
	return 0;
}