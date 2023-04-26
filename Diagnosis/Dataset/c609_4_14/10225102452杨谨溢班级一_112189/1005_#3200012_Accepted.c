# include<stdio.h>
# include <string.h>
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int out = 0;
		char str[20];
		scanf("%s", str);
		for (int j = 0;j<strlen(str);++j)
		{
			if (str[j] == '-') out = out * 3 - 1;
			else if (str[j] == '1')out = out * 3 + 1;
			else out *= 3;
		}
		printf("case #%d:\n%d\n", i, out);
	}
	return 0;
}