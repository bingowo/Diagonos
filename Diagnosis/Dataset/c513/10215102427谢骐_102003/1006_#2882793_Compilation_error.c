#include <stdio.h>
#include <string.h>

int main(void)
{
	int t, n = 0, len, j = 0;
	char s[30], tab[50] = {0};
	tab[49] = 1;
	tab[45] = -1;
	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		scanf("%s", s);
		len = strlen(s);

		while(j < len)
			N = N * 3 + tab[s[j++]];

	}

	return 0;
}