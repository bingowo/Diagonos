#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a, const void* b)  // 升序
{
	char* A = *(char**)a, * B = *(char**)b;
	int aa = strlen(A),bb = strlen(B);
	int aaa = atoi(A), bbb = atoi(B);
	if (aa != bb)   return bb - aa;
	else return aaa - bbb;
}

int main()
{
	//printf ("111\n");
	char L[100009][8];
	//printf ("222\n");
	int a = 0;
	while (scanf("%s", L[a++]) != EOF);
	//printf ("333\n");
	qsort(L, a, sizeof(L[0]), cmp);
	//printf ("444\n");
	for (int i = 0; i < a; ++i)
	{
		printf("%s ", L[i]);
	}
	return 0;
}