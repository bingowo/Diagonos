#include <stdio.h>

int main()
{
	char s[102] = {0};
	int i = 0;
	while ((s[++i] = getchar()) != '\n')
		;
	for (int j = 0; j < 102; ++j)
		if (s[j] < '0' || s[j] > '9')
			s[j] = '\0';
	int m = 0, start, end;
	for (int j = 1; j <= 100; ++j)
		if (s[j] != '\0' && s[j - 1] == '\0') {
			while (s[j] == '0')
				++j;
			end = start = j;
			while (s[end++] != '\0')
				;
			if (m < end - start)
				m = end - start;
		}
	printf("%d\n", m);
	return 0;
}