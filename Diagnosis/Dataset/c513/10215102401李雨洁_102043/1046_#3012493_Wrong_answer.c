#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool isValid(char *s)
{
	bool flag = true;
	if(!strcmp(s,"the") || !strcmp(s,"a") || !strcmp(s,"an") || !strcmp(s,"of") || !strcmp(s,"for") || !strcmp(s,"and"))
    {
		flag = false;
	}
	return flag;
}

void toLow(char *s)
{
	int i = 0;
	while(s[i] != '\0')
    {
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 'a' - 'A';
		}
		i++;
	}
}

int main()
{
	int T;
	scanf("%d\n",&T);
	getchar();
	char word[105];
	char ch;
	for(int t = 0; t < T; t++)
    {
		int sum = 0;
		int i = 0;
		while(scanf("%c",&ch) != EOF && ch != '\n')
		{
			if(ch != ' ')
			{
				word[i] = ch;
				i++;
			}
            else
            {
				word[i] = '\0';
				i = 0;
				toLow(word);
				if(isValid(word))
                    sum++;
			}
		}
		word[i] = '\0';
		toLow(word);
		if(isValid(word))
            sum++;
		printf("case #%d:\n",t);
		printf("%d",sum);
		if(t != T - 1)
        {
            printf("\n");
		}
	}
	return 0;
}
