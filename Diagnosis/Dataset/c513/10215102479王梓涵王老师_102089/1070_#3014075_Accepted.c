#include <stdio.h>

int map[21];

void solve()
{
	map[0] = 1, map[1] = 2, map[2] = 4, map[3] = 7;
	for(int i = 4; i <= 20 ; i ++){
		map[i] = 2 * map[i - 1];
		for(int j = i - 3, sgn = -1; j >= 0; j -= 2){
			map[i] += sgn * map[j];
			sgn *= -1;
		}
	}
}

int main()
{
	int n;
	solve();
	scanf("%d", &n);
	while(n != -1){
		printf("%d\n", map[n]);
		scanf("%d", &n);
	}
	
	return 0;
}