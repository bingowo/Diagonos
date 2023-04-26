#include <stdio.h>
#include <ctype.h>
unsigned long weight[25];

void stw(void);
int ispnum(int n, unsigned long num);
void sort(unsigned long *a, int n);
void calc(unsigned long *a, unsigned long *b, unsigned long *ans);
void printans(int i, unsigned long *ans);

int main(void)
{
	stw();
	unsigned long num = 0;
	unsigned long a[25] = {0};
	int n = 0;
	for (int i = 0; i < 25; i++) {
		scanf("%d", &a[i]);
		n++;
		if (getchar() == ',')
			;
		else
			break;
	}
	sort(a, n);
	for (int i = 24; i >= 0; i--)
		num += a[i] * weight[i];
	printf("%lu\n", num);
	return 0;
}

void stw(void)
{
	weight[0] = 1;
	int n = 25, i = 1;
	while (n--) {
		unsigned long num = weight[i - 1] + 1;
		while (1) {
			if (ispnum(i, num) != 0) {
				weight[i] = num;
				i++;
				break;
			} else
				num++;
		}
	}
}

int ispnum(int i, unsigned long num)
{
	int j = 0;
	while (j != i) {
		if (num % weight[j] == 0)
			return 0;
		j++;
	}
	return 1;
}

void sort(unsigned long *a, int n)
{
	int h = 0, t = n - 1;
	while (h < t) {
		unsigned long tmp = a[h];
		a[h] = a[t];
		a[t] = tmp;
		h++;
		t--;
	}
}