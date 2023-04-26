#include<stdio.h>
#include<string.h>
int main()
{
char input[100];
int a;
double b;
while(scanf("%s",input)!=EOF){
    if(strstr(input,".")==NULL){
        sscanf(input,"%d",&a);
        printf("%02x %02x %02x %02x\n",(a>>24)&0xff,(a>>16)&0xff,(a>8)&0xff,a&0xff);
    }
    else{
        sscanf(input,"%lf",&b);
        unsigned char *p=(unsigned char*)&b;
        printf("%02x %02x %02x %02x %02x %02x %02x %02x\n",p[0],p[1],p[2],p[3],p[4],p[5],p[6],p[7]);
    }
}
return 0;
}

