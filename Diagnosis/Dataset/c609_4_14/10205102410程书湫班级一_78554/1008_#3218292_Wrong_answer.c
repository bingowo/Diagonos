#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    int x;
    unsigned char *t;
    while((scanf("%s",s))!=EOF)
    {
        if((strchr(s,'.'))==NULL){
            int a=atoi(s);
            x=sizeof(a);
            //int* b=&a;
            t=(unsigned char*)(&a);
        }else{
            double a=atof(s);
            x=sizeof(a);
            //double* c=&a;
            t=(unsigned char*)(&a);
        }
        for(int i=0;i<x;i++)
        {
            printf("%02x ",*t++);
        }
        printf("\n");
    }
    return 0;
}
