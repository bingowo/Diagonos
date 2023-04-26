#include<stdio.h>
#include<string.h>
int main()
{
    int question,s,number,j,len,temp,digit;
    char Octal[55], decimal[155];
    scanf("%d",&question);

    for(s=0;s<question;s++)
    {
        printf("case #%d:\n",s);
        scanf("%s",Octal);
        number = 0;
        len = strlen(Octal) -1;
        for (; len != 1; --len)
        {
            digit = Octal[len] - '0';
            j = 0;
            do {
                    if (j < number)
                        temp = digit*10 + decimal[j] - '0';
                    else
                        temp = digit*10;
                    decimal[j++] = temp/8 + '0';
                    digit = temp%8;
                }
            while (digit!=0 || j < number);
            number = j;
        }
    decimal[number++] = '\0';
    printf("0.%s",decimal);
    printf("\n");

    }
    return 0;
}