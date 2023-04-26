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
            double* pa=&a;
            int aa=sizeof(a);
            for(int i=0;i<(aa/2);i++) {printf("%02x",(unsigned)pa);if(i+1>(aa/2)) printf(" ");}
        }
        else
        {
            b=atoi(s);
            int* pb=&b;
            int bb=sizeof(b);
            for(int i=0;i<(bb/2);i++) {printf("%02x",(unsigned)pb);if(i+1>(bb/2)) printf(" ");}
        }
    }
    return 0;
}