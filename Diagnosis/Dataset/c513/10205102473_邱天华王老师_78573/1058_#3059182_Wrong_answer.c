#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    char str[101];
    char c;
    int i=0;
    while((c = getchar()) != EOF)
    {
        str[i++]=c;
    }

    int len = strlen(str);
    char erase[100];
    int commentOne = 0;
    int commentMuch = 0;
    int CHAR = 0;
    int STR = 0;
    for(int i = 0; i < len;i++)
    {
        FLAG:
        if(str[i] == '/' && str[i + 1] == '/')
        {
            while(str[i] != '\n')
                i++;
        }

        if(str[i] == '/' && str[i+1] =='*')
        {
            i+=2;
            while (!(str[i] == '*' && str[i + 1] == '/'))
            {
                i++;
            }
            i += 2;
            goto FLAG;
        }

        if(str[i] =='\'')
        {
            int m=0;
            for(int j = 0; j <= 3; j++)
            {
                
                erase[m++]=str[i+j];
            }
            i += 4;
            goto FLAG;
        }

        if(str[i] == '"')
        {
            int j = i;
            int k = i;
            int m=0;
            while(str[i] != '\n')
            {
                if(str[i] == '"')
                    k = i;
                i++;
            }
            k++;
            for(int q = j; q < k; q++)
            {
                erase[m++]=str[q];
            }
            i = k;
            
            goto FLAG;
        }


        int m1=0;
        
        erase[m1++]=str[i];
        }
    printf("%s\n",erase);

    return 0;
}
