#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
     int T;
    scanf("%d",&T);
    for(int q=0;q<T;q++)
    {
        char *moose[36]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};

    char str[1001],code[6],text[501];

    int i=0,j,k;  char ch;  int flag,n=0;

    gets(str);

    while(str[i])

    {   j=0;

        while(str[i]=='.'||str[i]=='-') code[j++]=str[i++];     code[j]='\0';

        for(k=0; k<36; k++)

            if(strcmp(code,moose[k])==0)

            {   if(k<26) ch=k+65;  else ch=k+22;

                text[n++]=ch;  break; }

       

        flag=0;

        while(str[i]=='/') {flag++;i++;}

        if(flag==3) text[n++]=' ';  else if(flag==5) text[n++]='.';

    }
     printf("case #%d:\n",q);
    text[n]='\0';  printf("%s\n",text);
    }


}
