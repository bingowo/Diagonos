#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Solution(char *Octal) {
    char decimal[200];
    int len , numbers = 0;//numbers:十进制小数位数
    for (len = strlen(Octal) - 1; len > 1; len --) {
        int n = Octal[len] - '0';
        int j = 0;
        int temp;
        do {
            if (j < numbers)
                temp = n * 10 + decimal[j] - '0';
            else
                temp = n * 10;
            decimal[j++] = temp / 8 + '0';
            n = temp % 8;
        } while (n || j < numbers);

        numbers = j;        
    }
    decimal[numbers] = '\0';
    printf("0.%s\n", decimal);
}

int main()
{
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; t++){
        char s[55];
        scanf("%s", s);
        printf("case #%d:\n",t);
        Solution(s);
    }
    return 0;
}