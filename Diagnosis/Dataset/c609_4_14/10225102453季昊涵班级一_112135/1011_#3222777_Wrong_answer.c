#include <stdio.h>
#include <string.h>

int Pow(int a, int b) {
	if (b == 0)
		return 1;
	int out = a;
	for (int i = 1; i < b; i++)
		out = out * a;
	return out;
}

int main() {
	char a[1000];
	scanf("%s", a);
	int out = 0;
	int b = 0;
	int c = 0;
	int i = 0;
	while (a[i] != '.' && a[i] != 0) {
		if (a[i] == '0')
			out = out * 3 + 0;
		else if (a[i] == '1')
			out = out * 3 + 1;
		else if (a[i] == '2')
			out = out * 3 - 1;
		i++;
	}
	if (a[i] == '.') {
		i++;
		while (a[i] != 0) {
			if (a[i] == '0')
				b = b * 3 + 0;
			else if (a[i] == '1')
				b = b * 3 + 1;
			else if (a[i] == '2')
				b = b * 3 - 1;
			i++;
			c++;
		}
	}
	if (out > 0) {
		if (b < 0) {
			b = Pow(3, c) + b;
			out = out - 1;
		}
	} else if (out < 0) {
		if (b > 0) {
			b = Pow(3, c) - b;
			out = out + 1;
		}
	}
	if (b == 0)
		printf("%d", out);
	else if (out != 0)
		printf("%d %d %d", out, b, Pow(3, c));
	else
		printf("%d %d", b, Pow(3, c));
	return 0;
}