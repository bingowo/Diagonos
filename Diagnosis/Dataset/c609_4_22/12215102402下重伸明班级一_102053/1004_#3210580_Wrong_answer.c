#include<stdio.h>
int main()
{
    int a,z;  // a是输入进制 z是输出进制
    char num[100],c,b;
    int ming[100];
    scanf("%d",&a);
    int i=0;
    b=getchar();   //跳过空格
    while((c=getchar())!=' ')
    {
        num[i]=c;
        i++;
    }
    scanf("%d",&z);
    for(int m=0;m<i;m++)
    {
        if(num[m]>='0'&&num[m]<='9')
        {
            ming[m]=num[m]-'0';
        }
        if(num[m]>='a'&&num[m]<='z')
        {
            ming[m]=num[m]-'a'+10;
        }
    }
    
}