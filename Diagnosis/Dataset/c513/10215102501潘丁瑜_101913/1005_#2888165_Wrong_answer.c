#include<stdio.h>
#include<string.h>

int main()
{
    int numbers = 0;
    int len,T,i,digit,j;
    int temp;
    char decimal[155];
    char octal[155];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",octal);
        len = strlen(octal)-1;
        for(;len!=1;len--)
        {
            digit = octal[len]-'0';
            j = 0;
            do
            {
                if(j<numbers)
                    temp = digit*10 +decimal[j]-'0';
                else temp = digit*10;
                decimal[j++]= temp/8+'0';
                digit = temp%8;
            }while(digit || j<numbers);
            numbers = j;
        }
        decimal[numbers] = '\0';
        printf("case #%d:\n",i);
        printf("0.%s\n",decimal);
    }
    
    return 0;
}