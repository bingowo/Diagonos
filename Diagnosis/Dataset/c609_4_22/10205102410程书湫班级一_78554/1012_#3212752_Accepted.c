#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char Octal[55],decimal[155];
        int number=0;
        scanf("%s",Octal);
        int len=strlen(Octal);
        for(int i=len-1;i>1;i--)
        {
        int digit=Octal[i]-'0';
        int j=0;
        int numerator;
        do
        {
        numerator=10*digit+(j<number?decimal[j]-'0':0);
        decimal[j++]=numerator/8+'0';
        digit=numerator%8;
        }while(digit!=0 || j<number);
        number=j;
        }
        decimal[number]='\0';
        printf("case #%d:\n",cas);
        printf("0.%s\n",decimal);
    }
    return 0;
}