#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void _int(int x) {
    int i=sizeof(x);
    unsigned char *p=(unsigned char *)&x;
    while(i--)
        printf("%02x ",*p++);  //x：表示以十六进制形式输出，02：表示不足两位，前面补0输出，如果超过两位，则以实际输出
    printf("\n");
}

void _double(double x) {
    int j=sizeof(x);
    unsigned char *p=(unsigned char *)&x;
    while(j--)
        printf("%02x ",*p++);
    printf("\n");
}

int main()
{
    char a[100];  //不确定是int类型数据还是double类型数，所以数组输入
    while(scanf("%s",a)!=EOF) {
        if(strchr(a,'.')!=NULL)  //在字符串a中寻找并返回字符‘.'第一次出现的位置
            _double(atof(a));  //字符串中有小数点，读入数据需存放在double类型数据变量中，atof将字符串转换为douoble类型
        else
            _int(atoi(a));  //字符串中没有小数点，读入数据需存放在int类型数据变量中，atoi将字符串转换为int类型
    }
    return 0;
}
