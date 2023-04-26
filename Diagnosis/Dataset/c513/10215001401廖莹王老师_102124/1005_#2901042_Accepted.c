#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int n,h=0;
    scanf("%d",&n);
    for(h=0;h<n;h++)
    {
        char octal[55],decimal[155];
    int digit=0,temp=0;
    int j=0,i;
    scanf("%s",octal);
    int numbers=0,len=strlen(octal)-1;
    for(;len!=1;--len)
    {
        digit=octal[len]-'0';
        j=0;
        do
        {
            if(j<numbers)
                temp=digit*10+decimal[j]-'0';
            else temp=digit*10;
            decimal[j++]=temp/8+'0';
            digit=temp%8;
        }while(digit!=0 || j<numbers);
        numbers=j;
    }
    decimal[numbers]='\0';
    printf("case #%d:\n",h);
    printf("0.");
    for(i=0;decimal[i];i++)printf("%c",decimal[i]);
    printf("\n");
    }

    return 0;
}
