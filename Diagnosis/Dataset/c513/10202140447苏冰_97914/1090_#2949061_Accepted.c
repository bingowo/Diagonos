#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	while(1)
	{
	    scanf("%d",&n);
	    if(n==0) break;
	    int k=n*log10(n);
	    int a=pow(10,(n*log10(n)-k));
	    printf("%d\n",a);
	}
	return 0;
}
