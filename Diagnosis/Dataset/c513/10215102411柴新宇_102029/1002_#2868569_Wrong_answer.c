#include <stdio.h>
#include <string.h>


int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		char s[61] = {'\0'};
		scanf("%s", s);
		int table[256];
		for (int j = 0; j < 256; j++)
			table[j] = -1;
		table[s[0]] = 1;
		int flag = 1;
		int R = 1;
		int length = strlen(s);
		for (int j = 1; j < length; j++) {
			if (table[s[j]] == -1) {
				if (flag) {
					table[s[j]] = 0;
					flag = 0;
					R++;
				} else
					table[s[j]] = R++;
			}
		}
		if (R == 1)
			R = 2;
		long long result = 1;
		for (int j = 1; j < length; j++) {
			result = result * R + table[s[j]];
		}
		printf("case #%d:\n%d\n", i, result);
	}
	return 0;
}