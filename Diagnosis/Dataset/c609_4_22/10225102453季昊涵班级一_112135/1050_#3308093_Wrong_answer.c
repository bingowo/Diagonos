#include <stdio.h>
#include <string.h>

void addint(int a[], int b[], int c) {
	int len = a[0] > b[0] ? a[0] + 1 : b[0] + 1;
	int flag = c;
	int temp = 0;
	for (int i = 1; i <= len; i++) {
		temp = a[i] + b[i] + flag;
		a[i] = temp % 10;
		flag = temp / 10;
	}
	a[0] = len;
	return ;
}
int carry = 0;

void addf(int a[], int b[]) {
	int len = a[0] > b[0] ? a[0] + 1 : b[0] + 1;
	int flag = 0;
	int temp = 0;
	for (int i = len; i > 1; i--) {
		temp = a[i] + b[i] + flag;
		a[i] = temp % 10;
		flag = temp / 10;
	}
	if ((a[1] + b[1] + flag) >= 10) {
		a[1] = a[1] + b[1] + flag - 10;
		carry = 1;
	} else
		a[1] = a[1] + b[1] + flag;
	return ;
}

int main() {
	char a[600], b[600];
	int N;
	scanf("%s %s %d", &a, &b, &N);
	int ina[500] = {0}, inb[500] = {0}, dba[500] = {0}, dbb[500] = {0};
	int la = strlen(a);
	int lb = strlen(b);
	int fa = 0;
	int fb = 0;
	while (a[fa] != '.' && fa < la)
		fa++;
	while (b[fb] != '.' && fb < lb)
		fb++;
	ina[0] = fa;
	inb[0] = fb;
	dba[0] = la - fa - 1;
	dbb[0] = lb - fb - 1;
	int k = 1;
	for (int i = fa - 1; i >= 0; i--)
		ina[k++] = a[i] - '0';
	k = 1;
	for (int i = fb - 1; i >= 0; i--)
		inb[k++] = b[i] - '0';
	k = 1;
	for (int i = fa + 1; i < la; i++)
		dba[k++] = a[i] - '0';
	k = 1;
	for (int i = fb + 1; i < lb; i++)
		dbb[k++] = b[i] - '0';
	addf(dba, dbb);
	addint(ina, inb, carry);
	int temp = 0;
	if (dba[N + 1] > 4) {
		dba[N]++;
		temp = dba[N] / 10;
		dba[N] %= 10;
	}
	int n = N;
	while (temp && n > 1) {
		n--;
		int k = dba[n] + temp;
		dba[n] = k % 10;
		temp = k / 10;
	}
	int ii = 1;
	while (temp && ii <= ina[0]) {
		int k = ina[ii] + temp;
		ina[ii] = k % 10;
		temp = k / 10;
		ii++;
	}
	int len = ina[0];
	while (ina[len] == 0 && len > 1)
		len--;
	while (len > 0)
		printf("%d", ina[len--]);
	printf(".");
	for (int i = 1; i <= N; i++)
		printf("%d", dba[i]);




	return 0;
}