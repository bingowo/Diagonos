#include <stdio.h>
#include <stdlib.h>
char s[40]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\0"};//标准进制
int main()
{
    int num; //目标数字
    int x; //进制
    int q;//变量
    scanf("%d %d",&num,&x);
    char a[100];
    q=0;
    for(int j=x;num>0;num/=j)
    {
        int next;
        next=num%j;
        a[q++]=s[-next];
    }
    a[q]='\0';
    for(int o=0,u=--q;o<u;o++,u--)
    {
        char c;
        c=a[u];
        a[u]=a[o];
        a[o]=c;
    }
    printf("%s\n",a);
    return 0;
}
