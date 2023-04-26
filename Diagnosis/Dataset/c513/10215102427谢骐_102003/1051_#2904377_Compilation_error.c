#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char tmp[102];

void print_all(void);
void clear_left(void);
int not_end(int);
void put_ph(char, char, char);
void put_dchar(char);

int main(void)
{
	int num, idx = 0;
	scanf("%d", &num);
	while (num--) {
		printf("case #%d:\n", idx++);
		scanf("%s", tmp);
		clear_left();
		print_all();
		putchar('\n');
	}
	return 0;
}

void put_ph(char a, char b, char c)
{
	put_dchar(a >> 2);
	put_dchar((a << 4) + (b >> 4));
	put_dchar((b << 2) + (c >> 6));
	put_dchar(c);
}

void put_dchar(char ch)
{
	ch = ((ch << 2) >> 2);
	
}

void clear_left()
{
	int i = 0;
	while (tmp[i++] != '\0')
		;
	for ( ; i < 102; ++i)
		tmp[i] = '\0';
}

void print_all(void)
{
	for (int i = 0; i < 102; not_end(i) ? i += 3 : i = 102)
		put_ph(tmp[i], tmp[i + 1], tmp[i + 2]);
}

int not_end(int i)
{
	if (tmp[i] == '\0')
		return 0;
	else
		if (tmp[++i] == '\0')
			return 0;
		else
			if (tmp[++i] == '\0')
				return 0;
			else
				return 1;
}