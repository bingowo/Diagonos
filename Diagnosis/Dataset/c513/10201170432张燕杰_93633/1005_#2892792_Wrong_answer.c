#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i = 0;i<T;i++)
    {
        char octal[52]={'\0'};
        char decimal[155] = {'\0'};
        scanf("%s",octal);
        printf("case #%d:\n",i);

        int numbers = 0;
        int len = strlen(octal)-1;
        int temp;
        for(;len!=1;--len)
        {
            int digit = octal[len]-'0';
            int j = 0;
            do{
                if(j<numbers)
                    temp = digit*10 + decimal[j] - '0';
        else
            temp = digit*10;
        decimal[j++] = temp/8 + '0';
        digit = temp%8;
    } while (digit!=0 || j < numbers);
    numbers = j;

        }
        decimal[numbers] = '\0';
        printf("0.%s",decimal);
    }
    return 0;
}
