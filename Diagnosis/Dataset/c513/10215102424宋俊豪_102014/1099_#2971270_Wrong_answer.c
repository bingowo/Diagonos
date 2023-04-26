#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void sol(char b[])
{
    if(!strcmp(b,".-"))putchar('A');
    if(!strcmp(b,"-..."))putchar('B');
    if(!strcmp(b,"-.-."))putchar('C');
    if(!strcmp(b,"-.."))putchar('D');
    if(!strcmp(b,"."))putchar('E');
    if(!strcmp(b,"..-."))putchar('F');
    if(!strcmp(b,"--."))putchar('G');
    if(!strcmp(b,"...."))putchar('H');
    if(!strcmp(b,".."))putchar('I');
    if(!strcmp(b,".---"))putchar('J');
    if(!strcmp(b,"-.-"))putchar('K');
    if(!strcmp(b,".-.."))putchar('L');
    if(!strcmp(b,"--"))putchar('M');
    if(!strcmp(b,"-."))putchar('N');
    if(!strcmp(b,"---"))putchar('O');
    if(!strcmp(b,".--."))putchar('P');
    if(!strcmp(b,".-."))putchar('R');
    if(!strcmp(b,"..."))putchar('S');
    if(!strcmp(b,"-"))putchar('T');
    if(!strcmp(b,"..-"))putchar('U');
    if(!strcmp(b,"...-"))putchar('V');
    if(!strcmp(b,".--"))putchar('W');
    if(!strcmp(b,"-..-"))putchar('X');
    if(!strcmp(b,"-.--"))putchar('Y');
    if(!strcmp(b,"--.."))putchar('Z');
    if(!strcmp(b,"-----"))putchar('0');
    if(!strcmp(b,".----"))putchar('1');
    if(!strcmp(b,"..---"))putchar('2');
    if(!strcmp(b,"...--"))putchar('3');
    if(!strcmp(b,"....-"))putchar('4');
    if(!strcmp(b,"....."))putchar('5');
    if(!strcmp(b,"-...."))putchar('6');
    if(!strcmp(b,"--..."))putchar('7');
    if(!strcmp(b,"---.."))putchar('8');
    if(!strcmp(b,"----."))putchar('9');
    return ;
}
int main()
{
    int n;
    scanf("%d",&n);char s[1005],b[6];
    for(int i=0;i<n;i++)
    {   printf("case #%d:\n",i);
        scanf("%s",s);
        int len=strlen(s),id=0;
        for(int j=0;j<len;j++)
        {
            if(s[j]!='/')
            b[id++]=s[j];
            else if(s[j]=='/'&&s[j+1]=='/'&&s[j+2]=='/'&&s[j+3]=='/'&&s[j+4]=='/')
                {sol(b);
                putchar('.');
                memset(b,0,6);
                id=0;j+=4;
                }
            else if(s[j]=='/'&&s[j+1]=='/'&&s[j+2]=='/')
                {sol(b);printf(" ");

                memset(b,0,6);
                id=0;
                j+=2;}
            else if(s[j]=='/')
            {
                sol(b);
                memset(b,0,6);
                id=0;
            }
        }
         sol(b);
         memset(b,0,6);
        printf("\n");
    }
}
