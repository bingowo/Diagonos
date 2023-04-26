#include<stdio.h>
int main()
{
    int a,z;  // a是输入进制 z是输出进制
    char num[100],c,b;
    scanf("%d",&a);
    int i=0;
    b=getchar();   //跳过空格
    while((c=getchar())!=' ')
    {
        num[i]=c;
        i++;
    }
    scanf("%d",&z);
    printf("%c",num[--i]);
}