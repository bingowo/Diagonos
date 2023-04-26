#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[101];
    while(scanf("%s",str)!=EOF)
    {
        //检测小数点
        int flag=0;
        for(int i=0;i<strlen(str);i++)
            if(str[i]=='.')flag=1;
        //判断是double还是int
        if(flag==1)
        {
            //库函数atof(str)将str字符串转换为double
            double n=atof(str);
            //不同机器所占字节数不同,用sizeof()来检测
            int p=sizeof(n);
            unsigned char *e=(unsigned char*)&n;
            while(p--){printf("%02x ",*e++);}
        }
        else
        {
            //库函数atoi(str)将str字符串转换为int
            int n=atoi(str);
            int p=sizeof(n);
            unsigned char *e=(unsigned char*)&n;
            while(p--){printf("%02x ",*e++);}
        }
        printf("\n");
    }
}