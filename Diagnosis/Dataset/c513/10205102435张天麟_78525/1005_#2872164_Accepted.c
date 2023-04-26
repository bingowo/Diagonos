#include<stdio.h>
#include<string.h>
char Octal[55],decimal[155];
int main()
{
    int number,j,len,digit,temp,T,n,i;
    scanf("%d",&T);
    for(n=0;n<T;n++)
    {
        scanf("%s",Octal);
        number=0;
        len=strlen(Octal)-1;
        for(;len!=1;--len)
        {
            digit=Octal[len]-'0';
            j=0;
            do{
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
            }while(digit||j<number);
            number=j;
        }
        decimal[number]='\0';
        printf("case #%d:\n0.",n);
        for(i=0;i<strlen(decimal);i++)
        {
            printf("%c",decimal[i]);
        }
        printf("\n");
    }
    return 0;
}
