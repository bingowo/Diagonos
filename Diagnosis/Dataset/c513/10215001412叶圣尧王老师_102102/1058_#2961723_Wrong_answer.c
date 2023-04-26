#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char s[100];
    while(gets(s))
    {
       for(int i=0;i<strlen(s);i++)
       {
           if(s[i]=='"'){while(s[i+1]!='"'&&i<strlen(s))i++;i+=2;}
           if(s[i]=='/'&&s[i+1]=='/'){s[i]='\0';break;}
       }
       puts(s);
    }
}
