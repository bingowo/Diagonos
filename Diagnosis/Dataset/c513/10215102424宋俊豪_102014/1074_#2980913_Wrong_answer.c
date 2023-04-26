#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define MOD 210
#define MAX 1000000007
int subint(char* ch, int l, int r) {
	int s = 0;
	for (int i = l; i <= r; i++) {
		s *= 10;
		s += ch[i] - '0';
		s %= MOD;
	}
	return s;
}

int main()
{
    int f[101][210]={0};
    char s[101];
    scanf("%s",s);
    for (int i = 0; i < strlen(s); i++) {
	f[i][subint(s, 0, i)] += 1;
	f[i][subint(s, 0, i)] %= MAX;
	for (int j = 0; j < i; j++) {
		int tmp = subint(s, j + 1, i);
		for (int k = 0; k < MOD; k++) {
			f[i][(k + MOD + tmp)%MOD] += f[j][k];
			f[i][(k + MOD + tmp)%MOD] %= MAX;
			f[i][(k + MOD - tmp)%MOD] += f[j][k];
			f[i][(k + MOD - tmp)%MOD] %= MAX;
		}
	}
}
}
