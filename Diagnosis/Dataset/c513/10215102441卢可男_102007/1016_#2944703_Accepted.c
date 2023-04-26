
/*
负数进制的一个短除法运算如下：
-2	|	-15		8......1
-2	|	8		-4......0
-2	|	-4		2......0
-2	|	2		-1......0
-2	|	-1		1......1
-2	|	1		0......1
从下往上书写，就可以发现-15 = 110001 
*/ 
#include <stdio.h>
#include <string.h>
#include <math.h>

const double ep = 1e-8;

void itob(int n, char s[], double b)
{ 
	int remaindor = 0, quotient = 0, tempb = (int)b;
	int index = 18;
	while(n != 0){
		if(fabs(n / b) < ep){
			quotient = (int)(n / b);
		}else{
			quotient = ceil(n / b);
		}
		remaindor = n - tempb * quotient;
		s[index--] = remaindor >= 10 ? (remaindor - 10 + 'A') : (remaindor + '0');
		n = quotient;	
	};
	memmove(s, s + index + 1, 19 - index);
}

int main(void)
{
	int n, r;
	scanf("%d %d", &n, &r);
	char s[20] = {0};
	if(n == 0){
		printf("0");
	}else{
		itob(n, s, (double)r);
		printf("%s", s);	
	}

	return 0;
}