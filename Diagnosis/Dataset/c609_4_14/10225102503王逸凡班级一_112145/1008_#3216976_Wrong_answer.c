#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[60000];
    while(scanf("%s",a)!=EOF){
    int b=0;
    double c=0;
    int dx;
    if(strchr(a,'.')){
        c=atof(a);
    }else{
        b=atoi(a);
    }
    if(b!=0){
        dx=sizeof(int);
        int *p1=&b;
        unsigned char *p2=(unsigned char*)p1;
        for (int i=0;i<dx;i++){
            printf("%02x ",*(p2+i));
        }
    }else if(b==0&&c==0){
        printf("00 00 00 00");
    }else{
        dx=sizeof(double);
        double *p1=&c;
        unsigned char *p2=(unsigned char*)p1;
        for (int i=0;i<dx;i++){
            printf("%02x ",*(p2+i));
        }
    }
    printf("\n");
    }
    return 0;
}
