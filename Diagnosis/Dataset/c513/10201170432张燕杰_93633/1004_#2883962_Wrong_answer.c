#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
A:   while(getchar()!=EOF)
        {char s[100]={'0'};
        int count =0;
        while((s[count]=getchar())!='\n')
        {
            count++;
            continue;
        }
        int i;
        double d;
        if(strchr(s,'.')!=NULL)
        {
            d = atof(s);
            goto DOUBLE;
        }
        else
        {
            i = atoi(s);
            goto INT;
        }
        DOUBLE:
            {
                unsigned char* p;
                p = &d;
                for(int flag = 0;flag<8;flag++)
                {
                    printf("%02x ",*(p+flag));
                }
                goto A;
            }
        INT:
            {
                unsigned char* p;
                p = &i;
                for(int flag = 0;flag<4;flag++)
                {
                    printf("%02x ",*(p+flag));
                }
                goto A;
            }}

    return 0;
}

