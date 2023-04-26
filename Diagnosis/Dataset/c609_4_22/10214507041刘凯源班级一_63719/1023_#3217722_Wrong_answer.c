#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
const char model[20][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
void de(int *d, int *m, int*y,const char *s)
{
	*d = 0;
	*m = 0;
	*y = 0;
	char *tmp = strchr(s, '.');
	int point = (int)(tmp - s);
	int len = strlen(s);
//	printf("%d %d\n", len, point);
	for(int i = 0; i < point; ++i)
		*d = (*d) * 10 + s[i] - '0';
	char month[20] = {0};
	for(int i = 0; i + point + 2 <= len; ++i)
	{
		if(s[i + point + 2] == ' ')
			break;
		month[i] = s[i + point + 2];
	}
//	printf("%s %s\n", s, month);
	for(int i = 0; i < 19; ++i)
	{
		if(strcmp(month, model[i]) == 0)
		{
			*m = i;
			break;
		}
	}
	for(int i = point; i < len; ++i)
	{
		if(isdigit(s[i]))
			*y = (*y) * 10 + s[i] - '0';
	}
	return;
}
int cmp(void *p1, void *p2)
{
	char *a = *(char**)p1, *b = *(char**)p2;
	int d1, m1, y1;
	int d2, m2, y2;
	de(&d1, &m1, &y1, a);
	de(&d2, &m2, &y2, b);
//	printf("%d %d %d - %d %d %d\t", d1, m1, y1, d2, m2, y2);
	int res = y1 == y2 ? (m1 == m2 ? d1 - d2 : m1 - m2) : y1 - y2;
//	printf("%s %s %d\n", a, b, res);
	return res;
}
void sov()
{
	int n;
	char **s;
	s = (char**)malloc(sizeof(char*) * (n + 5));
	char tmpc;
	scanf("%d%c", &n, &tmpc);
	for(int i = 0; i < n; ++i)
	{
		s[i] = (char*)malloc(sizeof(char) * 20);
		gets(s[i]);
//		puts(s[i]);
	}
	qsort(s, n, sizeof(char*), cmp);
//	printf("1");
	for(int i = 0; i < n; ++i)
	{
		puts(s[i]);
	}
}
int main()
{
	int a, b, c;
	de(&a, &b, &c, "0. yoxkin 2012");
	printf("%d %d %d", a, b, c);
//	exit(0);
//	char s[][20] = {"8. yoxkin 20120", "0. pop 2000"};
//	printf("%d\n", cmp(s, s+20));
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		printf("case #%d:\n", i);
		sov();
	}
}
/*
2
2
8. yoxkin 2012
0. pop 2000
3
8. yoxkin 2012
9. yoxkin 2010
0. uayet 2012

*/