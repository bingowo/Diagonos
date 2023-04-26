#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a, const void* b)  // 升序
{
    int A = *(int*)a,B = *(int*)b;
    int a2 = 0,b2 = 0,a3 = abs(A),b3 = abs(B);
    //if (A<0) a2++;
    //if (B<0) b2++;
    while(b3)
    {
        if (b3) b2++;
        b3/=10;
    }
    while(a3)
    {
        if (a3) a2++;
        a3/=10;
    }
    if (a2 == b2)   return A-B;
    else return b2-a2;
}

int main()
{
	int a[100009];
	int n = 0,i;
	while(scanf("%d",&a[n])!= EOF) n++;
	qsort (a,n,sizeof(a[0]),cmp);
	for (i = 0;i<n;i++)
	{
	    printf("%d%c",a[i],i == n-1?'\n':' ');
	}
	return 0;
}