#include <stdio.h>
#include <string.h>

int main() {
	char in[100];
	scanf("%s", in);
	if(in=='0')
	printf("0");
	else{
		int len = strlen(in);
	long long int a = 0, b = 0;
	int f1;
	int j = 0;
	if (in[j] == '-') {
		j++;
		f1 = -1;
	} else
		f1 = 1;
	int k = j;
	if (in[len - 1] != 'i') {
		b = 0;
		for (int i = j; i < len; i++)
			a = a * 10 + in[k] - '0';
		a = a * f1;
	} else {
		while (j < len && in[j] != '-' && in[j] != '+' && in[j] != 'i')
			j++;
		if (in[j] != 'i') {
			for (; k < j; k++)
				a = a * 10 + in[k] - '0';
			a = a * f1;
			int f;
			if (in[j] == '-')
				f = -1;
			else
				f = 1;
			if (in[j + 1] == 'i')
				b = f;
			else {
				while (in[++j] != 'i')
					b = b * 10 + in[j] - '0';
				b = b * f;
			}
		} else {
			a = 0;
			for (; k < j; k++)
				b = b * 10 + in[k] - '0';
			b = b * f1;
		}
	}
	int out[1000];
	int p = 0;
	while (a != 0 || b != 0) {
		long long int qr, qi;
		int r;
		if ((a - b) % 2 == 0) {
			r = 0;
			out[p++] = r;
		} else {
			r = 1;
			out[p++] = r;
		}
		qr = (b - a + r) / 2;
		qi = qr - b;
		a = qr;
		b = qi;
	}
	for (int k = p - 1; k >= 0; k--)
		printf("%d", out[k]);
	}
	
	return 0;
}