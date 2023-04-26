#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

void trans(char str[]);

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char number[55];
        scanf("%s",number);
        printf("case #%d:\n",i);
        trans(number);
    }
    return 0;
}

void trans(char str[])
{
    int numbers=0,len,digit,temp;char decimal[155];
    len=strlen(str)-1;
    for(;len!=1;--len)
    {
        digit=str[len]-'0';
        int j =0;
        do
        {
            if(j<numbers)
                temp =digit*10+decimal[j]-'0';
            else
                temp = digit*10;
            decimal[j++]=temp/8+'0';
            digit = temp%8;
        }
        while(digit!=0||j<numbers);
        numbers=j;
    }
    decimal[numbers]='\0';
    printf("0.");
    for(int k=0;k<strlen(decimal);k++)
        printf("%c",decimal[k]);
    printf("\n");
}