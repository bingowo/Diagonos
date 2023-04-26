#include<stdio.h>
#include<string.h>
void print(const char* str)
{
    if(!strcmp(str,".-"))   {putchar('A');return;}
    if(!strcmp(str,"-...")) {putchar('B');return;}
    if(!strcmp(str,"-.-.")) {putchar('C');return;}
    if(!strcmp(str,"-.."))  {putchar('D');return;}
    if(!strcmp(str,"."))    {putchar('E');return;}
    if(!strcmp(str,"..-.")) {putchar('F');return;}
    if(!strcmp(str,"--."))  {putchar('G');return;}
    if(!strcmp(str,"....")) {putchar('H');return;}
    if(!strcmp(str,".."))   {putchar('I');return;}
    if(!strcmp(str,".---")) {putchar('J');return;}
    if(!strcmp(str,"-.-"))  {putchar('K');return;}
    if(!strcmp(str,".-..")) {putchar('L');return;}
    if(!strcmp(str,"--"))   {putchar('M');return;}
    if(!strcmp(str,"-."))   {putchar('N');return;}
    if(!strcmp(str,"---"))  {putchar('O');return;}
    if(!strcmp(str,".--.")) {putchar('P');return;}
    if(!strcmp(str,"--.-")) {putchar('Q');return;}
    if(!strcmp(str,".-."))  {putchar('R');return;}
    if(!strcmp(str,"..."))  {putchar('S');return;}
    if(!strcmp(str,"-"))    {putchar('T');return;}
    if(!strcmp(str,"..-"))  {putchar('U');return;}
    if(!strcmp(str,"...-")) {putchar('V');return;}
    if(!strcmp(str,".--"))  {putchar('W');return;}
    if(!strcmp(str,"-..-")) {putchar('X');return;}
    if(!strcmp(str,"-.--")) {putchar('Y');return;}
    if(!strcmp(str,"--..")) {putchar('Z');return;}
    if(!strcmp(str,"-----")){putchar('0');return;}
    if(!strcmp(str,".----")){putchar('1');return;}
    if(!strcmp(str,"..---")){putchar('2');return;}
    if(!strcmp(str,"...--")){putchar('3');return;}
    if(!strcmp(str,"....-")){putchar('4');return;}
    if(!strcmp(str,".....")){putchar('5');return;}
    if(!strcmp(str,"-....")){putchar('6');return;}
    if(!strcmp(str,"--...")){putchar('7');return;}
    if(!strcmp(str,"---..")){putchar('8');return;}
    if(!strcmp(str,"----.")){putchar('9');return;}
}
int main()
{
    int T;scanf("%d\n",&T);
    for(int cas=0;cas<T;++cas)
    {
        char c;int i=0;char str[10];int cnt=0;
        printf("case #%d:\n",cas);
        while((c=getchar())!='\n')
        {
            switch(i)
            {
                case 0:
                {
                    if(c!='/')str[cnt++]=c;
                    else {str[cnt]='\0';print(str);i=1;}
                    break;
                }
                case 1:
                {
                    if(c!='/'){cnt=0;str[cnt++]=c;i=0;}
                    else i=2;
                    break;
                }
                case 2: {i=3;break;}
                case 3: 
                {
                    if(c!='/'){printf(" ");cnt=0;str[cnt++]=c;i=0;}
                    else i=4;
                    break;
                }
                case 4: {i=5;break;}
                case 5: {printf(".");cnt=0;str[cnt++]=c;i=0;}
            }   
        }
        str[cnt]='\0';print(str);printf("\n");
    }
    return 0;
}