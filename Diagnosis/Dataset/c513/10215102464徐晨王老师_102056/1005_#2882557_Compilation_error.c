#include <stdio.h>#include <stdlib.h>#include <string.h>int main(){    char Octal[55], decimal[155];int numbers = 0;len = strlen(Octal) – 1;for (; len != 1; --len) {    digit = Octal[len] – ‘0’;    j = 0;    do {        if (j < numbers)            temp = digit*10 + decimal[j] – ‘0’;        else            temp = digit*10;        decimal[j++] = temp/8 + ‘0’;        digit = temp%8;    } while (digit!=0 || j < numbers);    number = j;}decimal[numbers] = ‘\0’;return 0;}