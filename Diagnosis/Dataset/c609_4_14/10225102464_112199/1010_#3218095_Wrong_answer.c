#include <stdio.h>
#include <stdlib.h>
char s[40]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\0"};//标准进制
int main()
{
    int num;
    int x;
    int q=0;
    scanf("%d %d",&num,&x);
    char a[1000];
    for(int j=x;num!=0;)
    {
        int next;
        next=num%j;
        int he;
        if(next<0)
        {
            next-=j;
            num/=j;
            num++;

        }
        else {
                num/=j;

        }
        a[q++]=s[next];
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