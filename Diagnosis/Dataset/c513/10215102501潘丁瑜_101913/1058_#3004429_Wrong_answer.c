#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char ch;
    char str[1000]={0};
    char res[1000]={0};
    int i=0,j=0,r;
    while((ch = getchar())!= EOF)
        str[i++] = ch;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i] == '"')
        {
            r = i+1;
            while(str[r] != '\n') r++;
            while(str[r] != '"') r--;
            if(str[r] == '"')
            {
                for(;i<=r;i++)
                    res[j++] = str[i];
            }
            i = r+1;
        }
        if(str[i] == 39)
        {
            r = i+1;
            while(str[r] != '\n' && str[r] != 39) r++;
            if(str[r] == 39)
            {
                for(;i<=r;i++)
                    res[j++] = str[i];
            }
            i = r+1;
        }
        if(str[i] == '/')
        {
            if(str[i+1] == '/')
            {
                i+=2;
                while(str[i] != '\n') i++;
                //res[j++] = str[i];
            }
            else if(str[i+1] == '*')
            {
                i+=2;
                for(r=i;r<strlen(str);r++)
                {
                    if(str[r] == '*' && str[r+1] == '/')
                    {
                        i=r+1;
                        break;
                    }
                }
                //res[j++] = str[i];
            }
        }
        else
            res[j++] = str[i];
    }
    printf("%s",res);
    return 0;
}