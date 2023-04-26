#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char octal[55],de[155];
        int digit,numbers=0,temp;
        scanf("%s",octal);
        int len=strlen(octal)-1;
        for(;len != 1;--len)
        {
            digit=octal[len]-'0';
            int j=0;
            do
            {
                if (j<numbers)
                    temp=digit*10+de[j]-'0';
                else
                    temp=digit*10;
                de[j++]=temp/8+'0';
                digit=temp%8;
            }
            while (digit != 0 || j<numbers);
            numbers=j;
        }
        de[numbers]='\0';
        printf("case #%d:\n%c",i,de[155]);
    }

}