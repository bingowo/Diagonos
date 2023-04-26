#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n;
    char Octal[55],decimal[155];
    scanf("%d",&n);
    int digit,j,temp,len;
    for(int i=0; i<n; i++)
    {
        scanf("%s",Octal);
        int numbers=0;
        len=strlen(Octal)-1;
        for(; len!=1; --len)
        {
            digit=Octal[len]-'0';
            j=0;
            do
            {
                if(j<numbers)
                    temp=digit*10+decimal[j]-'0';
                else
                    temp=digit*10;
                decimal[j++]=temp/8+'0';
                digit=temp%8;
            }
            while(digit || j<numbers);
            numbers=j;
        }
        decimal[numbers]='\0';
        printf("case #%d:\n0.%s\n",i,decimal);
    }
    return 0;
}