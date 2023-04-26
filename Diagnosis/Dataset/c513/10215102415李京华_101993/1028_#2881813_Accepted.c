#include <stdio.h>
#include <stdlib.h>

int cmpa(const void *a, const void *b)
{
	return (*(int *)a) - (*(int *)b);
}

int cmpd(const void *a, const void *b)
{
	return (*(int *)b) - (*(int *)a);
}

int main()
{
	char ch;
	scanf("%c", &ch);
	int a[100];
	int i, cnt = 0;
	while (scanf("%d", &a[cnt]) != EOF)
		cnt++;
	
	if (ch == 'A')
		qsort(a, cnt, sizeof(a[0]),cmpa);
	else
		qsort(a, cnt, sizeof(a[0]),cmpd);
	
	if (cnt == 1)
		printf("%d", a[0]);
	else{

		for (i = 0; i < cnt - 1; i++){
			if (a[i] != a[i+1])
				printf("%d ",a[i]);
		}
		printf("%d", a[cnt - 1]);
	}
		

	return 0;
}