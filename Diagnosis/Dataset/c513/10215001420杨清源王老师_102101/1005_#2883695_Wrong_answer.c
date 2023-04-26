#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int t, k = 0;
    scanf("%d\n",&t);
    for(; k < t ; k++)
    {
        char octal[55], decimal[55];
        scanf("%s\n",octal);
        int numbers = 0, len = strlen(octal) - 1, digit , i , j , temp;
        //numbers记录当前十进制小数位数

        for (; len != 1; --len)
        {
            digit = octal[len] - '0';
            j = 0;
            do
            {
                if (j < numbers)
                    temp = digit*10 + decimal[j] - '0';
                else
                    temp = digit*10;
                decimal[j++] = temp/8 + '0';
                digit = temp%8;
            }
            while (digit!=0 || j < numbers);
            numbers = j;
        }
        decimal[numbers] = '\0';


        printf("case #%d:\n",k);
        printf("0.");
        for(i = 0 ; i < numbers ; i++)
            printf("%d",decimal[i]);
        printf("\n");
    }

    return 0;
}
