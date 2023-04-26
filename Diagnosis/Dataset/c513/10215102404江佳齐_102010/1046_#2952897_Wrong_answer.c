#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int t;
    char s[100];
    scanf("%d",&t);
    gets(s);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        gets(s);
        int len=strlen(s),count=0;
        for(int j=0;j<len;j++)
        {
            if(s[j]==' ') count++;
            if(s[j]=='a'&&s[j+1]=='n'&&s[j+2]==' ') count--;
            if(s[j]=='a'&&s[j+1]=='n'&&s[j+2]=='d'&&s[j+3]==' ') count--;
            if(s[j]=='a'&&s[j+1]==' ') count--;
            if(s[j]=='t'&&s[j+1]=='h'&&s[j+2]=='e'&&s[j+3]==' ') count--;
            if(s[j]=='o'&&s[j+1]=='f'&&s[j+2]==' ') count--;
            if(s[j]=='f'&&s[j+1]=='o'&&s[j+2]=='r'&&s[j+3]==' ') count--;
            if(s[j]=='A'&&s[j+1]=='N'&&s[j+2]==' ') count--;
            if(s[j]=='A'&&s[j+1]=='N'&&s[j+2]=='D'&&s[j+3]==' ') count--;
            if(s[j]=='A'&&s[j+1]==' ') count--;
            if(s[j]=='T'&&s[j+1]=='H'&&s[j+2]=='E'&&s[j+3]==' ') count--;
            if(s[j]=='O'&&s[j+1]=='F'&&s[j+2]==' ') count--;
            if(s[j]=='F'&&s[j+1]=='O'&&s[j+2]=='R'&&s[j+3]==' ') count--;
        }
        printf("%d\n",count+1);
    }
    return 0;
}
