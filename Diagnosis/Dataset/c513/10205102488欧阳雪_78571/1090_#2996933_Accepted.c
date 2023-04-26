#include<stdio.h>
#include<math.h>
int main()
{
	int N;
	while(scanf("%d",&N))
	{
		if(N==0)
		{
			return 0;
		}
		double f=N*log10(N);
		f-=(int)f;
		int b=pow(10,f);
		printf("%d\n",b);
	}
}