#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_inum(char[]);
void show_byte(char *, int);

int main(void)
{
	char s[128] = {'\0'};
	int aint;
	int *intp = &aint;
	double adouble;
	double *doublep = &adouble;
	int wid;
	while (1) {
		if (get_inum(s)) {
			// it is a double
			adouble = atof(s);
			wid = 8;
			show_byte((char *)doublep, wid);
		} else {
			// it is an int
			aint = atoi(s);
			wid = 4;
			show_byte((char *)aint, wid);
		}
		putchar('\n');
	}
}

void show_byte(char *bite, int n)
{
	for (int i = 0; i < n; i++)
		printf("%x ", (unsigned)(char[i]));
}

int get_inum(char inum[])
{
	int i = 0, ch;
	while ((ch = getchar()) != '\n')
		inum[i++] = ch;
	inum[i] = '\0';
	for (int j = 0; j < strlen(inum); j++)
		if (inum[j] == '.')
			return 1;
	return 0;
}