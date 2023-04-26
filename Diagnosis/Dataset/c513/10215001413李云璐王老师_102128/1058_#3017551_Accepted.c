#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    char str[10000];
    char c;
    int len=0;
    while((c = getchar())!= EOF)
    {
        str[len]=c;
        len++;
    }
    str[len]='\0';


    char erase[10000];
    int d=0;
    int commentOne = 0;
    int commentMuch = 0;
    int CHAR = 0;
    int STR = 0;
    int i=0;
    for(int i=0;i<len;i++)
    {
        FLAG:
        if(str[i] == '/' && str[i + 1] == '/'&&str[i]!='\0')//单行注释见到换行符就不理
        {
            while(str[i] != '\n'&&str[i]!='\0')
                i++;
        }

        if(str[i] == '/' && str[i+1] =='*'&&str[i]!='\0')//多行注释结束之后要注意后面是否继续是单行注释
        {
            i+=2;
            while (!(str[i] == '*' && str[i + 1] == '/'))
            {
                i++;
            }
            i += 2;
            goto FLAG;
        }

        if(str[i] =='\'')//单引号中可能会出现双引号
        {
            for(int j = 0; j <= 3; j++)
            {
                erase[d]= str[i + j];
                d++;
            }
            i += 4;
            goto FLAG;
        }

        if(str[i] == '"')//双引号要遇到单行的最后一个双引号，然后把中间所有内容都加起来
        {
            int j = i;
            int k = i;
            while(str[i] != '\n')
            {
                if(str[i] == '"')
                    k = i;
                i++;
            }
            k++;
            for(int q = j; q < k; q++)
            {
                erase[d]= str[q];
                d++;
            }
            i = k;
            goto FLAG;

        }



        erase [d]= str[i];d++;
        }
        erase[d]='\0';

    printf("%s",erase);


    return 0;
}