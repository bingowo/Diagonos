#include <stdio.h>
#include <string.h>

int main() {
	int in;
	scanf("%x", &in);
	char temp[100];
	int i = 0;
	do {
		int t = in & 1;
		temp[i++] = t + '0';
		in = in >> 1;
	} while (in);
	char out[100];
	int k = 0;
	for (int j = i - 1; j >= 0; j--)
		out[k++] = temp[j];
	out[k] = '\0';
	long long int qr = 0, qi = 0;
	long long int a, b;
	for (int i = 0; i < k; i++) {
		int r = out[i] - '0';
		a = -qr - qi + r;
		b = qr - qi;
		qr = a;
		qi = b;
	}
	if (qi == 0) {
		printf("%lld\n", qr);
	} else {
		if (qr != 0) {
			printf("%lld", qr);
			if (qi > 0)
				printf("+");
		}
		if (qi == 1)
			printf("i\n");
		else if (qi == -1)
			printf("-i\n");
		else {
			printf("%lld", qi);
			printf("i\n");
		}
	}

	return 0;
}