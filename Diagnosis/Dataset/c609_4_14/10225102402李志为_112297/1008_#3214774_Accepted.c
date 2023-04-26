#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000]={0};
    double f;
    int d,t=0;
    int p[10];
    long long u;
    while((scanf("%s",s))!=EOF){
        t=0;
        for(int j=0;j<strlen(s);j++){
            if(s[j]=='.') {
                t=1;//t是1代表 小数
                break;
            }
        }
        if(t){
            f= atof(s);
            u=*(long long*)&f;
            int a=255;
            for(int i=0;i<8;i++){
                p[i] =a&u;
                u=u>>8;
            }
            for(int i=0;i<8;i++)
                printf("%02x ",p[i]);
            printf("\n");
        }
        else {
            d= atoi(s);
            int a=255;
            for(int i=0;i<4;i++){
                p[i] =a&d;
                d=d>>8;
            }
            for(int i=0;i<4;i++)
                printf("%02x ",p[i]);
            printf("\n");
        }
    }
    return 0;
}