#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char m[36][6]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        char s[1001];
        int i;
        gets(s);
        for(i=0;i<strlen(s);i++)
        {
            int j=0;
            char x[6];
            while(s[i]!='/'&&i<strlen(s))
            {
                x[j]=s[i];
                j++;
                i++;
            }
            x[j]='\0';
            for(j=0;j<36;j++)
            {
                if(strcmp(x,m[j])==0)
                {
                    if(j>9)
                        printf("%c",'A'+j-10);
                    else
                        printf("%d",j);
                }
            }
            if(s[i+1]=='/'&&s[i+2]=='/'&&s[i+3]=='/'&&s[i+4]=='/'&&s[i+5]=='/')
            {
                i+=4;
                printf(".");
            }
            else if(s[i+1]=='/'&&s[i+2]=='/'&&s[i+3]=='/')
            {
                i+=2;
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
