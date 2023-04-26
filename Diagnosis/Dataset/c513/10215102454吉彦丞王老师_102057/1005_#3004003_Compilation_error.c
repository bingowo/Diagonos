#include<stdio.h>
#include<string.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        char s[52];
        char c[55];
        numbers = 0;
        len = strlen(s) – 1;
        for (; len != 1; --len) {
            digit = s[len] – '0';
            j = 0;
            do {
                if (j < numbers)
                    temp = digit*10 + c[j] – '0';
                else
                    temp = digit*10;
                c[j++] = temp/8 + '0';
                digit = temp%8;
            } while (digit!=0 || j < numbers);
             numbers = j;
        }
        c[numbers] = '\0';
        printf("case #%d:\n",i);
        printf("0.%s\n",c);
    }
    return 0;
}