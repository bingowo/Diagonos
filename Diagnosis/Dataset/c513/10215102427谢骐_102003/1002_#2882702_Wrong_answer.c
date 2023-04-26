#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int tab[128];
	int t, n, j = 1, num = 2, flag = 0;
	long long ans = 0, weight = 1;
	char s[64];

	for(int i = 0; i < 128; ++i)
		tab[i] = -1;

	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		scanf("%s", s);
		n = strlen(s);
		tab[s[0]] = 1;

		while(s[j]) {
			if (tab[s[j]] == -1 && flag == 0) {
				tab[s[j++]] = 0;
				flag = 1;
			} else if(tab[s[j]] == -1 && flag == 1)
				tab[s[j++]] = num++;
			else j++;
		}

		weight = 1;
		j = 1;
		num = 2;
		flag = 0;
		ans = 0;
	}

	return 0;
}