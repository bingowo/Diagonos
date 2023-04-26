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
    int flag=0;
    int i=0;
    int sum=0;
    while(s[i]!='0')
    {
        i++;
        if(s[i]=='x')
        {
            char* c=(char*)malloc(sizeof(char)*100000);
            c[0]='0';
            c[1]='x';
            int j=2;
            for(j=2;s[j]!='x';j++)
            {
                strcpy(c,s);
            }
            c[j-1]='0';
            int len=strlen(c);
            for(int j=0;j<len;j++)
            {
                if(c[j]-'0'>=0&&c[j]-'0'<=9) sum+=sum*16+c[j]-'0';
                else sum+=sum*16+c[j]-'87';
            }
            printf("%u ",sum);
            sum=0;
            flag=1;
        }
    }
    if(!flag) printf("-1");
    return 0;
}
