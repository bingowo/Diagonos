#include <stdio.h>
#include <math.h>

typedef long long int lli;
lli map[32][32];

void solve(void){
	for(int i = 0; i < 32; i ++){
		map[i][i] = 1;             //当n==m时，只有一种情况 
	}
	for(int i = 1; i < 32; i ++){
		for(int j = 1; j < 32; j ++){
			if(i > j){
				map[i][j] = 2 * map[i-1][j]-map[i-j-1][j]+(1<<(i-j-1));
			}		
		}
	}
}


int main(void)
{
	lli n, m;
	scanf("%lld %lld", &n, &m);
	solve();
	while(n != -1 && m != -1){
		lli res = map[n][m];
		printf("%lld\n", res);
		scanf("%lld %lld", &n, &m);
	}
	
	return 0;
}