#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[17]={0};
    while(scanf("%s",s)!=EOF)
    {
        char *ret=strchr(s,'.');
        if(ret==0)
        {
            int i=atof(s);//字符串转浮点数
            int m=0;
            for(unsigned char* j=(unsigned char*)&i;m<sizeof(i);j++,m++)//按字节输出地址
                printf("%02x%c",*j,m!=sizeof(i)-1?' ':'\n');
        }
        else
        {
            double f=atof(s);
            int m=0;
            for(unsigned char* j=(unsigned char*)&f;m<sizeof(f);j++,m++)
                printf("%02x%c",*j,m!=sizeof(f)-1?' ':'\n');//保证每个宽度为2
        }
    }
    return 0;
}