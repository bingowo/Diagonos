#include<stdio.h>
#include<string.h>


int main()
{
    char str[10001];
    char c;
    int m=0;
	int len =0;
    while((str[m++]= getchar()) != EOF)
    

    
	 len= strlen(str);
    char erase[10001];

    for(int i = 0; i < len;i++)
    {

        if(str[i] == '/' && str[i + 1] == '/')
        {
            while(str[i] != '\n')
                i++;

        }

        if(str[i] == '/' && str[i+1] =='*')   //多行注释结束之后后面后面可能有单行注释
        {
            i+=2;
            while (!(str[i] == '*' && str[i + 1] == '/'))
            {
                i++;
            }
            i += 2;

        }

        if(str[i] =='\'')  //单引号中可能会出现双引号
        {
            for(int j = 0; j <= 3; j++)
            {
                erase[m++] = str[i + j];
            }
            i += 4;

        }

        if(str[i] == '"')  //双引号
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
                erase [m++]= str[q];
            }
            i = k;


        }



        erase [m++]= str[i];
        }

    for(int t = 0;t<m;t++)
    printf("%c",erase[t]);


    return 0;
}