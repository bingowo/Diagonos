#include<stdio.h>
#include<math.h>
int main()
{
	int n;	
	while(scanf("%d",&n)){
		if(n==0)
			break;		
		double m = n*log10(n),i = 0;
		double p = modf(m,&i);
		printf("%d\n",(int)pow(10,p));
		
	}
	return 0;
}