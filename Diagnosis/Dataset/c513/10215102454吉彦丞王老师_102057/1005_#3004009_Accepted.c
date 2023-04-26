#include<stdio.h>
#include<string.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        char s[55];
        scanf("%s",&s);
        char c[155];
        int numbers = 0;
        int len = strlen(s)-1;
        for (; len != 1; --len) {
            int digit =s[len]-'0';
            int j = 0;
            int temp;
            do {
                if (j < numbers)
                    temp = digit*10 + c[j]-'0';
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