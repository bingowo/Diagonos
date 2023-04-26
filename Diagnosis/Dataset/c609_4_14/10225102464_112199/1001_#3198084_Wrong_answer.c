#include <stdio.h>
#include <stdlib.h>
char s[40]={"123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\0"};//标准进制
int main()
{
    int n; //数据数量
    int num[20]; //目标数字
    int x[20]; //进制
    int q;//变量
    int sign;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&num[i],&x[i]);
    }
    for(int i=0;i<n;i++)
    {
        sign=num[i]<0?-1:1;
        if(sign==-1)
            num[i]=-num[i];
        q=0;
        char a[100];
        for(int j=x[i];num[i]>0;num[i]/=j)
        {
            int next;
            next=num[i]%j;
            a[q++]=s[next-1];
        }
        a[q]='\0';
        for(int o=0,u=--q;o<u;o++,u--)
        {
            char c;
            c=a[u];
            a[u]=a[o];
            a[o]=c;
        }
        if(sign==-1)
        printf("-%s\n",a);
        else
            printf("%s\n",a);
    }
    return 0;
}