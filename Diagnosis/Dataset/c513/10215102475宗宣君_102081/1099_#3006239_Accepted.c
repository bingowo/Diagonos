#include <stdio.h>
#include <string.h>
int main()
{   char *moose[36]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
    int T,p;
    scanf("%d\n",&T);
    for(p = 0;p<T;p++)
    {
    char str[1001],code[6],text[501];
    int i=0,j,k;
    char ch;
    int flag,n=0;
    gets(str);
    while(str[i])
    {   j=0;
        while(str[i]=='.'||str[i]=='-') code[j++]=str[i++];
        code[j]='\0';
        for(k=0; k<36; k++)
            if(strcmp(code,moose[k])==0)
            {   if(k<26) ch=k+65;  else ch=k+22;
                text[n++]=ch;
                break;
            }
        flag=0;
        while(str[i]=='/') {flag++;i++;}
        if(flag==3) text[n++]=' ';
        else if(flag==5) text[n++]='.';
    }
    text[n]='\0';
    printf("case #%d:\n%s\n",p,text);
    }
    return 0;
}
