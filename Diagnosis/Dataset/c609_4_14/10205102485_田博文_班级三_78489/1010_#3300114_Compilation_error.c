#include <stdio.h>
#include <math.h>
int main()
{
int decimal_num, base_num, quotient;
int remainders[32], i = 0; 
scanf("%d %d", &decimal_num, &base_num); 

do {
quotient = decimal_num / base_num; 
if (decimal_num % base_num < 0) { 
�⽤“R-��”作为当前�上的��
quotient++;
remainders[i++] = decimal_num - quotient * base_num;
}
else remainders[i++] = decimal_num % base_num; 
 decimal_num = quotient; 
} while (decimal_num != 0); 
i--; 
for (; i >= 0; i--) { 
if (remainders[i] > 9) printf("%c", remainders[i] + 55);

else printf("%d", remainders[i]); 
}
return 0;
}