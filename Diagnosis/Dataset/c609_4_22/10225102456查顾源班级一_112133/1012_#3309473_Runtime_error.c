#include <stdio.h>
#include <string.h>


int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        char Octal[55], decimal[155];
        int numbers = 0;
        int len = strlen(Octal) - 1;
        for (; len != 1; --len) {
            int digit = Octal[len] - '0';
            int j = 0;
            do {
                int temp;
                if (j < numbers)
                    temp = digit*10 + decimal[j] -'0';
                else
                temp = digit*10;
                decimal[j++] = temp/8 + '0';
                digit = temp%8;
            } while (digit!=0 || j < numbers);
            numbers = j;
        }
        decimal[numbers] = '\0';
        printf("case #%d:\n",i);
        for(int j=0;j<strlen(decimal);j++)
            printf("%c",decimal[j]);
        printf("/n");
    }
    return 0;
}