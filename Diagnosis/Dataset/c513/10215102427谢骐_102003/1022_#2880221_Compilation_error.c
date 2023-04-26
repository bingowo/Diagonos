#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addrcmp(const void *, const void *);
void find_at(char **);
int UserNameCmp(char *, char *);

int main(void)
{
	unsigned n;
	scanf("%u", &n);
	char *addrs[n];

	for (int i = 0; i < n; i++) {
		char email[BUFSIZ*];
		scanf("%s", email);
		addrs[i] = (char *)calloc(strlen(email) + 1u, sizeof(char));
		strcpy(addrs[i], email);
	}

	if (n > 1)
		qsort(addrs, n, sizeof(addrs[0]), addrcmp);

	for (int i = 0; i < n; i++)
		printf("%s\n", addrs[i]);

	return 0;
}

int UserNameCmp(char *un1, char *un2)
{
	while (*un1 != '@' && *un1 == *un2)
		*un1++, *un2++;

	if (*un1 == '@')
		return -1;
	else
		return (unsigned char) * un1 - (unsigned char) * un2;
}

void find_at(char **p)
{
	while (**p != '@')
		(*p)++;
}

int addrcmp(const void *addr1, const void *addr2)
{
	char *domainName1 = *(char **)addr1, *domainName2 = *(char **)addr2;
	find_at(&domainName1);
	find_at(&domainName2);
	int diff_domainName = strcmp(domainName1, domainName2);

	if (diff_domainName != 0)
		return diff_domainName;
	else
		return -UserNameCmp(*(char **)addr1, *(char **)addr2);
}