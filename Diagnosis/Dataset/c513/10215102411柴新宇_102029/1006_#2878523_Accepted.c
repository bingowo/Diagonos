#include <stdio.h>
#include <string.h>



int main() {
	int T;
	scanf("%d", &T);
	int table[256] = {0};
	table['0'] = 0;
	table['1'] = 1;
	table['-'] = -1;
	for (int i = 0; i < T; i++) {
		printf("case #%d:\n", i);
		char str[69] = {'\0'};
		scanf("%s", str);
		int length = strlen(str);
		int num = 0;
		for (int j = 0; j < length; j++)
			num = num * 3 + table[str[j]];
		printf("%d\n", num);
	}
	return 0;
}