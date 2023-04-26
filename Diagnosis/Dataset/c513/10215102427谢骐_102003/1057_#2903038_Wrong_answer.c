#include <stdio.h>
#include <ctype.h>
unsigned char w[999 + 1 + 999] = {0};
int left = 999, right = 999;

void insert_num(unsigned char);

int main(void)
{
	w[999] = getchar();
	--left, ++right;
	int ch;
	while ((ch = getchar()) != '\n')
		insert_num(toupper(ch));
	printf("%s\n", w + left + 1);
	return 0;
}

void insert_num(unsigned char ch)
{
	if (ch >= w[left - 1])
		w[left--] = ch;
	else
		w[right++] = ch;
}