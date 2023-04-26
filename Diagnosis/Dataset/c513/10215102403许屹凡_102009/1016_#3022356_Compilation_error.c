#include <stdio.h>

int main()
{
	int n,r; scanf("%d %d",&n,&r);
	char tochar[]={ '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J' };
	char s[30] = '0'; char* p = s;
	while(n)
	{
			if (n % r < 0){
					*p++ = tochar[ n - r*(n / r + 1) ];
					n = n / r;
			}	else{
				*p++ = tochar[ n % r ];
				n = n / r;	
			}
	}
	char *q = s; p-- ; 
	int temp;
	while( p > q ){
		temp = char *p-- ; 
		char *p = char *q;
		char *q++ = temp;
	}
	
	printf("%s",s) ; 
	return 0;
}