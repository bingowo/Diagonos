#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0; cas<T; cas++){
        char Octal[55];
        scanf("%s",Octal);
    char decimal[155];
    int numbers = 0;int digit;
    int len = strlen(Octal) - 1;
    for (; len != 1; --len) {
    digit = Octal[len] - '0';
    int j = 0,temp;
    do {
        if (j < numbers)
            temp = digit*10 + decimal[j] - '0';
        else
            temp = digit*10;
        decimal[j++] = temp/8 + '0';
        digit = temp%8;
    } while (digit!=0 || j < numbers);
    numbers = j;
}
decimal[numbers] = '\0';
printf("case #%d:\n%s\n",cas,decimal);
    }

    return 0;
}
