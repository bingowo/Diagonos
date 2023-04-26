#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char octal[55],decimal[155];//分别储存八进制和十进制小数,用char防止损失
        scanf("%s",&octal);
        int digit,temp;
        int numbers=0;
        int len=strlen(octal)-1;//末尾‘0’
        for(;len!=1;len--)
        {
            digit=octal[len]-'0';
            int j=0;
            do
            {
                if(j<numbers)
                    temp=digit*10+decimal[j]-'0';
                else
                    temp=digit*10;
                decimal[j++]=temp/8+'0';
                digit=temp%8;
            }while(digit||j<numbers);
            numbers=j;
        }
        decimal[numbers]='\0';
        printf("case #%d：\n",i);
        printf("0.%s",decimal);
        }
    return 0;
}