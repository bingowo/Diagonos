#include <stdio.h>
#include <stdlib.h>


int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF){
        if(strchr(s,'.')==NULL){
            int a;
            a=atoi(s);
            int *p1;
            p1=&a;
            unsigned char* p2;
            p2=(unsigned char*)p1;
            int b=sizeof(a);
            for(int j=0;j<b;j++){
                printf("%02x",*p2++);
            }
        }
        else{
            double a;
            a=atof(s);
            double *p1;
            p1=&a;
            unsigned char* p2;
            p2=(unsigned char*)p1;
            int b=sizeof(a);
            for(int j=0;j<b;j++){
                printf("%02x",*p2++);
            }
        }
        printf("\n");
    }
    return 0;
}
