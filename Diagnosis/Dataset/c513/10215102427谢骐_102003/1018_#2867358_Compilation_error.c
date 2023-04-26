#include <stdio.h>
#include <ctype.h>
int weight[25] = {
	1,  2,  3,  5,  7, 11, 13, 17, 19, 23,
	29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
	71, 73, 79, 83, 89,
};

void sort(int a[], int n);

int main(void)
{
	unsigned long sum = 0;
	int a[25] = {0};
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
		num = (num + a[i]) * weight[i];
	printf("%lu\n", num);
	return 0;
}

void sort(int *a, int n)
{
	int h = 0, t = n - 1;
	while (h < t) {
		int tmp = a[h];
		a[h] = a[t];
		a[t] = tmp;
		h++;
		t--;
	}
}