#include <stdio.h>

int main() {
	char data[80];
	scanf("%s", &data);
	int i = 1;
	int maxlen = 1;
	int len = 1;
	int flg = 0;
	while (data[i] != '\0') {
		if (data[i] != data[i - 1]) {
			len++;
			flg = 0;
		} else {
			if (maxlen < len) {
				maxlen = len;
			}
			len = 1;
			flg = 1;
		}
		i++;
	}
	if (flg == 0 && len != 0 && maxlen < len + 1)
		maxlen = len;
	printf ("%d\n", maxlen);
	return 0;
}