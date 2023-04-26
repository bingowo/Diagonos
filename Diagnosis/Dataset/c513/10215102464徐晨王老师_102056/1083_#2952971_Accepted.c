#include <stdio.h>


int main(void)
{
	int T;
	scanf("%d", &T);
	for(int t=0;t<T;t++){
		int n;
		scanf("%d", &n);
		int nn=5;
		int sum=0;
		while(n/nn> 0){
			sum=sum+n/nn;
			nn=nn*5;
		}
		printf("case #%d:\n", t);
		printf("%d\n",sum);
	}
	
	return 0;
 } 
