#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_inum(char[]);
void show_byte(char *, int);

int main(void)
{
	char s[128] = {'\0'};
	int aint;
	double adouble;
	char *intp = (char *)&aint, *doublep = (char *)&adouble;
	int wid;
	while (1) {
		if (get_inum(s)) {
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
}

void show_byte(char *bite, int n)
{
	for (int i = 0; i < n; i++)
		printf("%02x ", bite[i]);
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