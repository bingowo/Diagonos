#include<stdio.h>
int tongji(char *a)
{
    
}
int main()
{
    int x;
    char b[100];
    gets(b); //跳过第一个空格
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        char a[150];
        gets(a);
        printf("%s\n",a);
    }
}