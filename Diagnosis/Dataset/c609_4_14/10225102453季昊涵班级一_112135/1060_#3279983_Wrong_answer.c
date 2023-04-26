#include <stdio.h>
#include <string.h>

int main() {
	char s[204];
	scanf("%s", s);
	int f = 0;
	int len = strlen(s);
	int sign[100] = {0};
	for (int i = 0; i < len; i++) {
		if (s[i] > s[i + f + 1]) {
			sign[i] = 1;
			f++;
		}
	}
	for (int i = 0; i < len; i++) {
		if (sign[i] == 0)
			printf("%c%c", s[i], s[i]);
		else
			printf("%c", s[i]);
	}



	return 0;
}