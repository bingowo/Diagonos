#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000];
    scanf("%s",s);
    while(strcmp(s,"END")!=0)
    {
        int x,y,z;
        int len=strlen(s);int num=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]==',') num++;
            if(num==1) y=(s[i+3]-'0')*10+(s[i+4]-'0'),z=(s[i+5]-'0')*10+(s[i+6]-'0');
            if(num==7) {x=(s[i+1]-'0')*10+(s[i+2]-'0');break;}
        }
        printf("14:09:50\n");
        scanf("%s",s);
    }
}