#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int is_double;
	char sol;
} ln_info;

ln_info get_inum(char[]);
void show_byte(unsigned char *, int);

int main(void)
{
	char s[32] = {'\0'};
	int aint;
	double adouble;
	unsigned char *intp = (unsigned char *)&aint,
				   *doublep = (unsigned char *)&adouble;
	int wid;
	ln_info ln;

	while (1) {
		ln = get_inum(s);

		if (ln.sol == EOF)
			break;

		if (ln.is_double == 1) {
			// it is a double
			adouble = atof(s);
			wid = 8;
			show_byte(doublep, wid);
		} else {
			// it is an int
			aint = atoi(s);
			wid = 4;
			show_byte(intp, wid);
		}

		putchar('\n');
	}

	return 0;
}

void show_byte(unsigned char *bite, int n)
{
	for (int i = 0; i < n; i++)
		printf("%02x ", bite[i]);
}

ln_info get_inum(char inum[])
{
	ln_info t;

	if ((t.sol = getchar()) == EOF)
		return t;
	else
		inum[0] = t.sol;

	int i = 1, ch;

	while ((ch = getchar()) != '\n')
		inum[i++] = ch;

	inum[i] = '\0';
	t.is_double = 1;

	for (int j = 1; j < strlen(inum); j++)
		if (inum[j] == '.')
			return t;

	t.is_double = 0;
	return t;
}