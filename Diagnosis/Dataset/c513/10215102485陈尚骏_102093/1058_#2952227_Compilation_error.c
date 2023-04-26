#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000001];
    char c;
    while((c=getchar())!= EOF)
    {
        s+= c;
    }
    int len = strlen(s);
    char ers;
    for(int i=0;i<len;i++)
    {
        FLAG:
        if(s[i]=='/'&&s[i + 1]=='/')
        {
            while(s[i]!='\n')
                i++;
        }
        if(s[i]=='/'&&s[i+1]=='*')
        {
            i+=2;
            while (!(s[i]=='*'&&s[i+1]=='/'))
            {
                i++;
            }
            i+=2;
            goto FLAG;
        }
        if(s[i]=='\'')
        {
            for(int j=0;j<= 3;j++)
            {
                ers+=s[i+j];
            }
            i+=4;
            goto FLAG;
        }

        if(s[i]=='"')
        {
            int j = i;
            int k = i;
            while(s[i]!='\n')
            {
                if(s[i]=='"')
                    k = i;
                i++;
            }
            k++;
            for(int q=j;q<k; q++)
            {
                ers+=s[q];
            }
            i=k;
            goto FLAG;
        }
        ers+=s[i];
    }
    printf("%s",ers);
    return 0;
}
