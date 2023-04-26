#include <stdio.h>
int pnum[25] = {
	1,  2,  3,  5,  7, 11, 13, 17, 19, 23,
	29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
	71, 73, 79, 83, 89,
};
int p2d[25][64] = {
	{1, 0},
	{2, 0},
	{6, 0},
	{0, 3, 0},
};	//4 of 25
unsigned long long pin[25] = {0};
unsigned long long ans[64] = {0};
void scanpin(void);
void stp2d(void);
void crct(int);
void calc(void);
void crctans(void);

int main(void)
{
	scanpin();
	stp2d();
	calc();
	int i = 63;
	while (ans[i] == 0 && i != 0)
		i--;
	for (; i >= 0; i--)
		printf("%llu", ans[i]);
	putchar('\n');
	return 0;
}
void calc(void)
{
	for (int i = 0; i <= 24; i++) {
		for (int j = 0; j <= 63; j++)
			ans[j] += pin[i] * p2d[i][j];
		crctans();
	}
}
void crctans(void)
{
	for (int i = 62; i >= 0; i--) {
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	for (int j = 0; j <= 62; j++) {
		ans[j + 1] += ans[j] / 10;
		ans[j] %= 10;
	}
}
void stp2d(void)
{
	for (int i = 4; i <= 24; i++) {
		for (int j = 0; j < 64; j++)
			p2d[i][j] = p2d[i - 1][j] * pnum[i];
		crct(i);
	}
}
void crct(int i)
{
	for (int j = 23; j >=0; j--) {
		p2d[i][j + 1] += p2d[i][j] / 10;
		p2d[i][j] %= 10;
	}
	for (int j = 0; j <= 23; j++) {
		p2d[i][j + 1] += p2d[i][j] / 10;
		p2d[i][j] %= 10;
	}
}
void scanpin(void)
{
	int n = 0;
	for (int i = 0; i < 25; i++) {
		scanf("%llu", &pin[i]);
		n++;
		if (getchar() == ',')
			;
		else
			break;
	}
	int h = 0, t = n - 1;
	while (h < t) {
		unsigned long long tmp = pin[h];
		pin[h] = pin[t];
		pin[t] = tmp;
		h++;
		t--;
	}
};