#include <stdio.h>
#include <string.h>

int main() {
	char s[60];
	scanf("%s", s);
	int out = 0;
	int temp = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] != s[i + 1])
			temp++;
		if (s[i] == s[i + 1] || i == strlen(s) - 1) {
			if (temp > out)
				out = temp;
			temp = 0;
		}
	}
	printf("%d\n", out + 1);

}