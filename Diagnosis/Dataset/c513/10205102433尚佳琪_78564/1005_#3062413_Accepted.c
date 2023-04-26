#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char Octal[55],decimal[155];
        int digit=0,temp=0,numbers=0,j;
        scanf("%s",Octal);
        int len=strlen(Octal)-1;
        for(;len!=1;--len)
        {
            digit=Octal[len]-'0';
            j=0;
            do{
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
        printf("case #%d:\n0.%s\n",i,decimal);
    }
    return 0;
}
