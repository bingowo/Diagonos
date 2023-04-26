#include <stdio.h>
#include <string.h>
 
int check(const char *);        //校验函数
 
int main()
{
    char str[1000];
    int hour=0,min=0,sec=0;
 
    while(strcmp(gets(str),"END")!=0)
    {
        if(strncmp(str,"$GPRMC",6)==0)
        {
            if(check(str)==1)       //如果校验正确
            {
                int i=7;
                for(;str[i]!=',';i++);    //循环体内为空语句，只为定位逗号
 
                i++;
 
                if(str[i]=='A')         //并且已定位
                {
                    hour=(str[7]-'0')*10+(str[8]-'0')+8;
                    if(hour>=24)
                        hour-=24;
                    min=(str[9]-'0')*10+(str[10]-'0');
                    sec=(str[11]-'0')*10+(str[12]-'0');
                }
            }
        }
    }
 
    printf("%02d:%02d:%02d",hour,min,sec);
 
    return 0;
}
 
int check(const char *p)
{
    int ret;
    int i=3,c=p[1]^p[2];
 
    for(i=3;p[i]!='*';i++)      //异或
        c=c^p[i];
    i++;
 
    int sum=0;
    for (;p[i]!='\0';i++)
    {
        if(p[i]>='0'&&p[i]<='9')
            sum = sum*16+p[i]-'0';
 
        else if(p[i]>='A'&&p[i]<='F')
            sum = sum*16+p[i]-'A'+10;
    }
 
    if(sum==c%65536)   //校验和正确
        ret=1;
    else                    //校验和错误
        ret=0;
 
    return ret;
}