#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int i,j,u,digit,numbers,len,temp,T;
    char Octal[10][55],decimal[10][55],c;
    scanf("%d",&T);
    c=getchar();
    for(i=0;i<T;i++)
    {
        u=0;
        while((c=getchar())!='\n')
        {
            Octal[i][u]=c;
            u++;
        }
        Octal[i][u]=0;
    }
    for(i=0;i<T;i++)
    {
    numbers=0;
    len=strlen(Octal[i])-1;
    for(;len!=1;--len)
    {
        digit=Octal[i][len]-'0';
        j=0;
        do{
            if(j<numbers)
                temp=digit*10+decimal[i][j]-'0';
            else
                temp=digit*10;
            decimal[i][j++]=temp/8+'0';
            digit=temp%8;
        }while(digit||j<numbers);
        numbers=j;
    }
    decimal[i][numbers]='\0';
    }
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        printf("0.");
        printf("%s\n",decimal[i]);
    }
    return 0;
}