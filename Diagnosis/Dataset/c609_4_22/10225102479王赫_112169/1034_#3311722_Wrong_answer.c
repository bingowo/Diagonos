#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 1000001

int main()
{
    char s[MAX_LENGTH];
    fgets(s,MAX_LENGTH,stdin);
    int len=strlen(s);
    if(s[len-1]=='\n') s[len-1]='\0';
    int flag=0;
    int i=0;
    while(s[i++]!='\0')
    {
        if(s[i]=='0'&&s[i+1]=='x'&&isdigit(s[i+2]))
        {
            unsigned int sum=0;
            for(i=i+2;s[i+2]!='x'; i++)
            {
                if(s[i]>='0'&&s[i]<='9') sum+=sum*16+s[i]-'0';
                else sum+=sum*16+s[i]-'a'+10;
               }
            printf("%u ",sum);
            flag++;
        }
    }
    if(!flag) printf("-1");
    return 0;
}
