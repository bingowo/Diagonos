#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i,len,hour,min,sec;
    char s[1000];
    while(scanf("%s",s))
    {
        if(strcmp(s,"END")!=0)
        {
            
        }
        else
        {
            printf("%02d:%02d:%02d",hour,min,sec);
            break;
        }
    }

    return 0;
}
