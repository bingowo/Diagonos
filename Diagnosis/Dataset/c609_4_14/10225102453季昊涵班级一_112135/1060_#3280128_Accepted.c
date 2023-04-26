#include <stdio.h>
#include <string.h>

int main() {
	char s[204];
	scanf("%s", s);
	int f = 0;
	int len = strlen(s);
	int sign[100] = {0};
	for (int i = 0; i < len; i++) {
		while (f < len && s[i] == s[f])
			f++;
		if (f < len && s[f] > s[i])
			sign[i] = 1;
	}
	for (int i = 0; i < len; i++) {
		if (sign[i] == 1)
			printf("%c%c", s[i], s[i]);
		else
			printf("%c", s[i]);
	}



	return 0;
}