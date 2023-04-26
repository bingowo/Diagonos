#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char*ChangeToBinary(unsigned int x,char*binary)
{
    int i;
    //
    for(i = 0;i < 10;i++)
    {
        binary[9 - i] = ((x>>i)&1) + '0';//值并没有输入到binary中
    }
    binary[10] = '\0';
    return binary;
}
int main()
{
    char input[501];
    char binary[11];
    scanf("%s",input);
    printf("0001");
    printf("%s",ChangeToBinary(strlen(input),binary));
    int unit = strlen(input)/3;
    int remainder = strlen(input)%3;
    int i;
    if(unit != 0)
    {
        for(i = 0;(i+3) <= strlen(input); i += 3)
        {
            printf("%s",ChangeToBinary((input[i] - '0')*100 + (input[i+1] - '0')*10 + (input[i+2] - '0')*1,binary));
        }
    }
    if(remainder == 1)
    {
        char remainder1[5];

        for(i = 0;i < 4;i++)
        {
            remainder1[3 - i] = (((unsigned)(input[unit*3] - '0')>>i)&1) + '0';
        }
        remainder1[4] = '\0';
        printf("%s",remainder1);
    }
    else if(remainder == 2)
    {
         char remainder1[8];
        for(i = 0;i < 7;i++)
        {
            remainder1[6 - i] = (((unsigned)((input[unit*3] - '0')*10 + (input[unit*3 + 1] - '0'))>>i)&1) + '0';
        }
        remainder1[7] = '\0';
        printf("%s",remainder1);
    }
    putchar('\n');

    return 0;
}
