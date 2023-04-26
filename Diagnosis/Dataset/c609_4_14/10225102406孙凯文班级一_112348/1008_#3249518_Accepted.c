#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char s[100];
    double a;
    int b;
    while(scanf("%s",s)!=EOF)
    {
        char *p=strstr(s,".");
        if(p!=NULL)
        {
            a=atof(s);
            unsigned char* pa=&a;
            int aa=sizeof(a);
            for(int i=0;i<aa;i++) {printf("%02x",*pa++);if(i!=aa-1) printf(" ");}
            printf("\n");
        }
        else
        {
            b=atoi(s);
            unsigned char* pb=&b;
            int bb=sizeof(b);
            for(int i=0;i<bb;i++) {printf("%02x",*pb++);if(i!=bb-1) printf(" ");}
            printf("\n");
        }
    }
    return 0;
}
