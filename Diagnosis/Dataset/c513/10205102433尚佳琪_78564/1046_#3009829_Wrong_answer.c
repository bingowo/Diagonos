#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        char s[105];
        gets(s);
        int len=strlen(s);
        char c[105];
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            int temp=0;
            c[0]='\0';
            if(s[i]!=' ')
                c[temp++]=s[i];
            else if(s[i]==' '||i==len-1)
            {
                c[temp]='\0';
                if(strcmp(c,"the")==0||strcmp(c,"a")==0||strcmp(c,"of")==0||strcmp(c,"an")==0||strcmp(c,"for")==0||strcmp(c,"and")==0);
                else
                    cnt++;

            }

        }
        printf("case #%d:\n%d\n",i,cnt);

    }
    return 0;
}
