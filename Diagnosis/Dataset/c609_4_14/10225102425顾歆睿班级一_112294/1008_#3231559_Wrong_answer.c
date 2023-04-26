#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000];
    while(scanf("%s",a)!=EOF){
        int n,y,*y1;
        double x,*x1;
        unsigned char *p;
        if(strchr(a,'.')){
                x=atof(a);
                x1=&x;
                n=sizeof(double);
                p=(unsigned char*)x1;
        }
        else{
                y=atoi(a);
                y1=&y;
                n=sizeof(int);
                p=(unsigned char*)y1;
        }
        while(n--){
            printf("%02x ",*p);
            p++;
        }
        printf("\n");
    }
    return 0;
}