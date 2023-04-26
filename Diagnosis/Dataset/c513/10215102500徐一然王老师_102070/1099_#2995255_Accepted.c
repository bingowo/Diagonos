#include <stdio.h>
#include <string.h>
char *moose[36]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};

int main()
{
    int count,count1;
    scanf("%d\n",&count);
    count1=count;
    char s[2000];

    char copy[10];
    while(count--)
    {
        gets(s);
        char *p=s;
        printf("case #%d:\n",count1-count-1);
        int cnt=0;
        for(int j=0;j<10;j++)
        {
                    copy[j]='\0';
        }
        while(1)
        {
            if(*p!='/'&&*p!='\0')
            {
                copy[cnt]=*p;
                cnt++;
                p++;
            }
            else if(*p=='/'&&*(p-1)=='/')
            {
                int flag=1;
                while(*p=='/')
                {
                    p++;
                    flag++;
                }
                if(flag==3)printf(" ");
                else printf(".");

            }
            else
            {
                for(int i=0;i<36;i++)
                {
                    if(strcmp(copy,moose[i])==0)
                    {
                        if(i<26)
                            printf("%c",'A'+i);
                        else
                            printf("%c",'0'+i-26);
                        break;
                    }
                }
                for(int j=0;j<10;j++)
        {
                    copy[j]='\0';
        }
                cnt=0;
                if(*p=='\0')break;
                p++;
            }

        }
        printf("\n");
    }
}
