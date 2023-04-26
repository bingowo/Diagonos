#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double Tab[26];

int cmp(const void *_a, const void *_b){
	char *a = (char *)_a;
	char *b = (char *)_b;
	
	int p = *a - 'A';
	int q = *b - 'A';
	if (*a >= 'a')
		p -= 32;
	if (*b >= 'a')
		q -= 32;

	if (Tab[p] != Tab[q]){
		if (Tab[p] > Tab[q])
			return -1;
		return 1;
	}

	if (p == q)
		return *b - *a;

	return p - q;
	
	
	
}

int main()
{
	int _T, T;
	scanf("%d", &T);
	for (_T = 0; _T < T; _T++){
		int i;
		for (i = 0; i < 26; i++)
			scanf("%lf", &Tab[i]);
			
		char s[101];
		scanf("%s", s);
		
		qsort(s, strlen(s), sizeof(s[0]), cmp);
		
		//输出
		printf("case #%d:\n",_T);
		printf("%s\n",s);
	}
	return 0;
}