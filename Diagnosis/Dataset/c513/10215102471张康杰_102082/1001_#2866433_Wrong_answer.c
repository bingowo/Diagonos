#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input,remainder,base;
    int index = 0;
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d %d",&input,&base);
    char output[32];
    if(input < 0)
    {
        input = -input;
        putchar('-');
    }
    do
    {
        remainder = input%base;
        output[index++] = table[remainder];
        input /= base;
    }while(input != 0);
    index--;
    for(index;index != -1;index--)
    {
        printf("%c",output[index]);
    }
    return 0;
}