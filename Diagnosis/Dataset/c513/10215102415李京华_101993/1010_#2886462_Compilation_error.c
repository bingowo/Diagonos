#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char L[501];
	scanf("%s",L);
	printf("0001");

	int ret[10] = {0};
	int i = 9;
	int m = strlen(L);
	while (m) {
		ret[i--] = m & 1;
		m /= 2;
	}
	for (i = 0; i < 10; i++)
		printf("%d", ret[i]);

	int j;
	for (i = 0; i < strlen(L); i += 3) {
		m = 3;
		if ((strlen(L) - i) < 3)
			m = strlen(L) - i;

		int a[3 * m + 1] = {0};
		char s[m];
		for (j = 0; j < m; j++)
			s[j] = L[i + j];
		int res = atoi(s);
		int j = 3 * m;
		while (res){
			a[j--] = res & 1;
			res /= 2;
		}

		//输出
		for (j = 0; j < 3 * m + 1; j++)
			printf("%d", a[j]);
	}
	return 0;
}
