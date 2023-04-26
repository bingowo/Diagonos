#include<stdio.h>
#include<stdlib.h>
long long f[60];
int main(){
	int t, i, j, n;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		memset(f,0,sizeof(f));
		scanf("%d", &n);
		f[0] = 1;
		for(j = 1; j <= n; ++j){
			if(j - 1 >= 0)	f[j] += f[j-1];
			if(j - 2 >= 0)	f[j] += f[j-2];
			if(j - 3 >= 0)	f[j] += f[j-3];
			if(j - 4 >= 0)	f[j] += f[j-4];
		}
		printf("case #%d:\n%lld\n", i, f[n]);
	}
	return 0;
}