#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    int t,i;
    for(t=0;t<T;t++)
    {
        char octal[55];
        scanf("%s",octal);
        //printf("%s\n",octal);
        char decimal[155];
        for(i=0;i<155;i++){decimal[i]='0';}
        int j;
        int len=strlen(octal)-1,number=0;
        for(;len>1;len--)
        {
            int temp;//记录十进制位数
            j=0;
            int digit=octal[len]-'0';//初始为八进制的这一位，后续为余数
            do
            {
                if(j<number)
                {
                    temp=digit*10+decimal[j]-'0';
                }
                else
                {
                    temp=digit*10;
                }
                decimal[j++]=temp/8+'0';
                digit=temp%8;
            }while((digit!=0)||(j<number));
            number=j;
        }
        decimal[number]='\0';
        printf("case #%d:\n",t);
        printf("0.%s\n",decimal);
    }
    return 0;
}
