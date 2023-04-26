#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main(){
	int num, cnt = 0;
	long long temp = 0;
	long long m, n;
	char c;
	scanf("%lld", &m);
	if(m == 1)printf("(0, 1)");
	else{
		temp = (long long)sqrt(m);
		n = temp / 2;
		cnt = m - (2*n-1)*(2*n-1);
		if(cnt > 6*n-1)printf("(%d, %d)", n, cnt-7*n+1);
		else if(cnt > 4*n-1)printf("(%d, -%d)", cnt-5*n+1, n);
		else if(cnt > 2*n-1)printf("(-%d, %d)", n, 3*n-cnt-1);
		else printf("(%d, %d)", n-cnt, n+1);
	}
	
	return 0;
}