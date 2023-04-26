//这里我们引用了string.h库里的比较函数strcmp()和复制函数strpy()
#include<stdio.h>
#include<string.h>
int main()
{
    char a[201][201];//首先我们建立一个存放输入字符串的二维数组
    char b[201];//再建立一个临时存放字符串的数组
    int n;
    scanf("%d",&n);//n个字符串
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);//实际上，二维数组的每一行存放一个字符串
    for(int i=0;i<n;i++)//控制行数，从第一行开始
    for(int j=i+1;j<n;j++)//从i的下一行开始
    {
        if(strcmp(a[i],a[j])>0)//不断比较前一个与后一个
        {//如果前一个字符的ASCII码大于后一个则交换位置
        //这个则由strcmp的值来反应，如果前一个元素大于后一个元素
        //则返回值1，如果相等返回值0，如果小于，返回值-1
            strcpy(b,a[i]);//利用临时数组存放字符串
            strcpy(a[i],a[j]);//将括号里的第二个元素赋给第一个元素
            strcpy(a[j],b);//结果是后一个与前一个交换
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%s\n",a[i]);//将每一行的字符串打印出来
    }
}

