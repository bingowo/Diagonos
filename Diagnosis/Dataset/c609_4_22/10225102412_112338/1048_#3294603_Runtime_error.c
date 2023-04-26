#include <stdio.h>

int f(int n)
{
	int m;
	if (n==0) m=0;
	else if (n==1) m=1;
	else m=f(n-1)+f(n-2);
	return m;
}

int main()
{
	int T;int *a;int i;
	scanf("%d",T);
	for (i=0;i<T;i++){
		scanf("%d",a[i]);
		printf("case #%d:\n%d",i,f(a[i]));
	}
	return 0;
} 