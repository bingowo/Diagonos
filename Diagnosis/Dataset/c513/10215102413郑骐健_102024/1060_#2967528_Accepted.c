#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int jud(char ch,char a)
{
    if(ch>='a'&&ch<='z')return 0;
    else if(ch==a||ch=='\n')return 0;
    else if(ch>='A'&&ch<='Z')return 0;
    else return 1;
}

int main()
{
    char ch;
    int ca=1;
    int max =0;
    int at =0;
    while((ch =getchar())!=EOF)
    {
        switch(ca)
        {
            case 1:
                {
                    at =0;
                    if(jud(ch,'0'))
                    {
                        at++;
                        ca=2;
                    }
                    break;
                }
            case 2:
                {
                    if(jud(ch,EOF))
                    {
                        at++;
                       
                    }
                    else ca =1;
                    break;
                }
        }
         max =(max<at)?at:max;
    }
    printf("%d",max);
    return 0;
}
