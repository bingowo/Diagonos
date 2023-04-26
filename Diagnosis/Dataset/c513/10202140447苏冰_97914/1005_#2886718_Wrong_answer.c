#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    int numbers,digit,j,temp,len;
    char s[60];
    char t[150];
    for(int i=0;i<T;i++)
    {
       scanf("%s",s);
       numbers=0;
       len=strlen(s)-1;
       for(;len!=1;len--)
       {
           digit=s[len]-'0';
           j=0;
           do
           {
               if(j<numbers)
                temp=digit*10+t[j]-'0';
               else
                temp=digit*10;
               t[j++]=temp/8+'0';
               digit=temp%8;
           }while(digit!=0 || j<numbers);
           numbers=j;
       }
       t[numbers]='\0';
       printf("%c%c",'0','.');
       printf("%s\n",t);
    }
    return 0;
}
