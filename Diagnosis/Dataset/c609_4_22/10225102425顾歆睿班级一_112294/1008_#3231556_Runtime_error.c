#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    while(scanf("%s",a)!=EOF){
        int n;
        unsigned char *p;
        if(strchr(a,'.')){
                double x=atof(a),*x1=&x;
                n=sizeof(double);
                p=(unsigned char*)x1;
        }
        else{
                int y=atoi(a),y1=&y;
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