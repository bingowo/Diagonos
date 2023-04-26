#include <stdio.h>
#include <string.h>

int main()
{
	char s[60];
	scanf("%s", s);
	int len = strlen(s), maxlen = 1;
	for (int i = 0; i < len-1; i++)
	{
		int x = 1;
		while (s[i] != s[i+1] && i < len-1)
		{
			x++;
			i++;
		}
		if(x > maxlen) maxlen = x;
	}
	printf("%d", maxlen);
	return 0;
}