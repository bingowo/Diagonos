#include <stdio.h>
#include <string.h>

//整数类型和小数类型处理方式不同，创建不同函数处理

void doint(int n);
void dodouble(double d);

int main()
{
    char s[31];//读入最长为32位的数据
    while(scanf("%s",s) != EOF)
    
        if(strchr(s,'.') == 0)//没有小数点
            doint(atoi(s));
        else
            dodouble(atof(s));
    

    return 0;
}

void doint(int n)
{
	int c = sizeof(n);
	unsigned char* p = (unsigned char*)&n;
	while(c--)
		printf("%02x ",*p++);
	printf("\n");
} 

void dodouble(double d)
{
	int c = sizeof(d);
	unsigned char* p = (unsigned char*)&d;
	while(c--)
		printf("%02x ",*p++);
	printf("\n");
} 