#include<stdio.h>
#include<math.h> 
const int N=12;
int main()
{
	int n,i;
	double L[12];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		L[i]=pow(2.0,a*1.0);
	}
	for (i=0;i<n;i++)
	{
		printf("case #%d:\n%.0f\n",i,L[i]);
	}
	return 0; 
}