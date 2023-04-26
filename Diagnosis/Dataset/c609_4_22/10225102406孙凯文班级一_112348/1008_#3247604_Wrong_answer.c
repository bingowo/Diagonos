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
            for(int i=0;i<aa;i++) {printf("%02x ",(unsigned)*pa);*(pa++);}
            printf("\n");
        }
        else
        {
            b=atoi(s);
            int* pb=&b;
            int bb=sizeof(b);
            for(int i=0;i<bb;i++) {printf("%02x ",(unsigned)*pb);}
            printf("\n");
        }
    }
    return 0;
}
