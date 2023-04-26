#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve()
{
    char *moose[36]={".-","-...","-.-.","-..","."."..-.","--.","....",\
        "..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...",\
        "-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---",\
        "...--","....-",".....","-....","--...","---..","----."};
    char s[1010],text[501],code[6];
    gets(s);
    int i=0,j,k,n=0,flag;
    char ch;
    while(s[i])
    {
        j=0;
        while(s[i]=='.'||s[i]=='-')
            code[j++]=s[i++];
        code[j]='\0';
        for(k=0;k<36;k++)
        {
            if(strcmp(code,moose[k])==0)
            {
                if(k<26) ch=k+65;
                else ch=k+22;
                text[n++]=ch;
                break;
            }
        }
        if(k>=36)
        {
            printf("Data Error!\n");
            return;
        }
        flag=0;
        while(s[i]=='/')
        {
            flag++;i++;
        }
        if(flag==3) text[n++]=' ';
        else if(flag==5) text[n++]='.';
    }
    text[n]='\0';
    printf("%s\n",text);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int m=0;m<t;m++)
    {
        printf("case #%d:\n",m);
        solve();
    }
    return 0;
}
