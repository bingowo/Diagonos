#include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        char Octal[55];
        char decimal[155];
        int len,digit,j,temp;
        int m,numbers;
        scanf("%d",&m);
        for(int s=0;s<m;s++)
        {
            scanf("%s",Octal);
            numbers=0;
            len = strlen(Octal) - 1;
            for (; len != 1; --len) {
            digit = Octal[len] -'0';
            j = 0;
            do
                {
                if (j < numbers)
                    temp = digit*10 + decimal[j] -'0';
                else
                    temp = digit*10;
                decimal[j++] = temp/8 + '0';
                digit = temp%8;
                }while (digit!=0 || j < numbers);
            numbers = j;
        }
        printf("case #%d:\n",s);
        decimal[numbers] = '\0';
        printf("0.%s\n",decimal);
        }
        return 0;
    }