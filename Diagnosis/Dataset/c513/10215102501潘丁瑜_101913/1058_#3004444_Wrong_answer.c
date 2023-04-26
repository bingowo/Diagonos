#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char ch;
    char str[100000]={0};
    char res[100000]={0};
    int i=0,j=0,r;
    while((ch = getchar())!= EOF)
        str[i++] = ch;
    for(i=0;i<strlen(str);i++)
    {
        //双引
        if(str[i] == '"')
        {
            r = i+1;
            while(str[r] != '\n') r++;
            while(str[r] != '"') r--;//从后开始找
            if(str[r] == '"')
            {
                for(;i<=r;i++)
                    res[j++] = str[i];
            }
            i = r+1;
        }
        //单引
        if(str[i] == 39)
        {
            r = i+1;
            while(str[r] != '\n') r++;
            while(str[r] != 39) r--;
            if(str[r] == 39)
            {
                for(;i<=r;i++)
                    res[j++] = str[i];
            }
            i = r+1;
        }
        // ‘/’
        if(str[i] == '/')
        {
            //单行注释
            if(str[i+1] == '/')
            {
                i+=2;
                while(str[i] != '\n') i++;//跳过
                i-=1;//下一步有i++
            }
            //双行注释
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
            }
        }
        else
            res[j++] = str[i];
    }
    printf("%s",res);
    return 0;
}
