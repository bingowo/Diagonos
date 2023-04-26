#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input,remainder,base;
    int index = 0;
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d %d",&input,&base);
    char output[32];
    do
    {
        remainder = input%base;
        output[index] = table[remainder];
        input /= base;
        index++;
    }while(input == 0);
    for(index;index;index--)
    {
        printf("%c",output[index]);
    }
    return 0;
}