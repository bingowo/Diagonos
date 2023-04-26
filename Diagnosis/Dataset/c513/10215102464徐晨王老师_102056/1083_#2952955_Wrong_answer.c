#include <stdio.h>


int main(void)
{
	int T;
	scanf("%d", &T);
	for(int t = 0 ; t < t; t ++){
		int n, temp;
		scanf("%d", &n);
		int n1 = 2, n2 = 5;
		int cnt1 = 0, cnt2 = 0;
		while(n / n1 > 0){
			cnt1 += (n / n1);
			n1 *= 2;
		}
		while(n / n2 > 0){
			cnt2 += (n / n2);
			n2 *= 5;
		}
		printf("case #%d:\n", t);
		printf("%d\n",cnt1);
	}
	
	return 0;
 } 
