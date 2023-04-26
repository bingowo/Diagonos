#include<stdio.h>
int main(){
    int chance;
    int i;
    scanf("%d",&chance);
    int numbers = 0;
int len = strlen(Octal) – 1;
char Octal[55], decimal[155];
for (; len != 1; --len) {
    int digit = Octal[len] – ‘0’;
    int j = 0;
    do {int temp;
        if (j < numbers)
            temp = digit*10 + decimal[j] – ‘0’;
        else
            temp = digit*10;
        decimal[j++] = temp/8 + ‘0’;
        digit = temp%8;
    } while (digit!=0 || j < numbers);
    number = j;
}
decimal[numbers] = ‘\0’;

}