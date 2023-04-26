#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* a;
a = (int*)malloc(1000009*sizeof(int));
int cmp(const void* a, const void* b)  // 升序
{
    int A = *(int*)a,B = *(int*)b;
    int a2 = 0,b2 = 0;
    char aa[12];
    char bb[12];
    sprintf(aa,"%d",A);
    sprintf(bb,"%d",B);
    a2 = strlen(aa);
    b2 = strlen(bb);
    if (A<0) a2--;
    if (B<0)  b2--;
    if (a2 == b2)   return A<B?-1:1;
    else return b2-a2;
}

int main()
{
	int n = 0,i;
	while(scanf("%d",&a[n])!= EOF) n++;
	qsort (a,n,sizeof(a[0]),cmp);
	for (i = 0;i<n;i++)
	{
	    printf("%d%c",a[i],i == n-1?'\n':' ');
	}
	return 0;
}