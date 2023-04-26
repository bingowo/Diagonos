#include <stdio.h>
#include <stdlib.h>
int Tab[26];
int cmp(const void *_a, const void *_b);
int main()
{
	char S[27];
	int i;
	while(scanf("%s\n",S) != EOF){
		//顺序S
		for (i = 0; i < 26; i++)
			Tab[S[i] - 'A'] = i;

		char L[2200];
		char a[100][21];
		gets(L);
		int cnt = 0;
		i = 0;
		while (1) {
			int j = 0;
			while (L[i] && L[i] != ' ')
				a[cnt][j++] = L[i++];

			a[cnt][j] = '\0';
			++cnt;
			if (!L[i])
				break;
			i++;
		}

		qsort(a, cnt, sizeof(a[0]), cmp);

		//输出
		for (i = 0; i < cnt; i++){
			printf("%s",a[i]);
			if (i != cnt - 1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}

int cmp(const void *_a, const void *_b){
	char *a = (char *)_a;
	char *b = (char *)_b;
	while (*a && *b){
		char s1 = (*a) >= 'a'? *a - 32 : *a;
		char s2 = (*b) >= 'a'? *b - 32 : *b;
		if (Tab[s1 - 'A'] != Tab[s2 - 'A'])
			return Tab[s1 - 'A'] - Tab[s2 - 'A'];
		a++;
		b++;
	}

	if (*a == 0)
		return - 1;
	return 1;
}