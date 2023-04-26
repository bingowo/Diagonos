#include <stdio.h>
unsigned long long octf[50][150] = {
	{0, 0},
	{0, 1, 2, 5, 0},		// 1
	//  1 ... n
	{0, 0, 1, 5, 6, 2, 5},	// 2
	//  1  2  3  4 ...2n
	0,
};

void init_octf(void);
void work(void);
void scan_octf(unsigned long long *);
void calc(unsigned long long *, unsigned long long *);
void print_df(unsigned long long *);
void crct(unsigned long long *);

int main(void)
{
	init_octf();
	int n, i = 0;
	scanf("%d", &n);
	getchar();
	while (n--) {
		printf("case #%d:\n", i++);
		work();
		putchar('\n');
	}
	return 0;
}

void work(void)
{
	unsigned long long inum[50] = {0}, onum[150] = {0};
	scan_octf(inum);
	calc(inum, onum);
	print_df(onum);
}

void print_df(unsigned long long *onum)
{
	printf("0.");
	int n = 149;
	while (onum[n] == 0)
		n--;
	for (int i = 1; i <= n; i++)
		putchar((int)onum[i] + '0');
}

void calc(unsigned long long *inum, unsigned long long *onum)
{
	for (int i = 1; i <= 49; i++)
		for (int j = 1; j <= 149; j++) {
			onum[j] += inum[i] * octf[i][j];
			crct(onum);
		}
}

void scan_octf(unsigned long long *ioctf)
{
	int ch;
	getchar();
	getchar();
	for (int i = 1; i <= 49; i++) {
		ch = getchar();
		if (ch >= '0' && ch <= '9')
			ioctf[i] = (unsigned long long)(ch - '0');
		else
			break;
	}
}

void init_octf(void)
{
	for (int i = 3; i <= 49; i++) {
		int n = 149;
		while (octf[i - 1][n] == 0)
			n--;
		for (int j = 3; j >= 1; j--)
			for (int k = n; k >= 1; k--) {
				octf[i][j + k] += octf[1][j] * octf[i - 1][k];
				crct(octf[i]);
			}
	}
}

void crct(unsigned long long *theoct)
{
	for (int j = 1; j <= 149; j++) {
		theoct[j - 1] += theoct[j] / 10ULL;
		theoct[j] %= 10ULL;
	}
	for (int j = 149; j >= 1; j--) {
		theoct[j - 1] += theoct[j] / 10ULL;
		theoct[j] %= 10ULL;
	}
}