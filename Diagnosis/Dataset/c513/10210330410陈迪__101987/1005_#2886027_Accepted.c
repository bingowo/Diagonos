#include <stdio.h>`
#include <string.h>

int main()
{
    int T;scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char Octal[50],decimal[150];scanf("%s",Octal);
        int number=0;
        int len = strlen(Octal)-1;
        for( ;len!=1;--len) {
            int digit = Octal[len] - '0';
            int j = 0;
            do {
                int temp;

                if(j<number)
                    temp = digit*10 + decimal[j] - '0';
                else
                    temp = digit*10;

                decimal[j++] = temp/8 + '0';
                digit = temp % 8;
            } while(digit!=0||j<number);
            number = j;
        }
        decimal[number]='\0';
        printf("case #%d:\n0.%s%c",cas,decimal,(cas==T-1?' ':'\n'));
    }
    return 0;
}
