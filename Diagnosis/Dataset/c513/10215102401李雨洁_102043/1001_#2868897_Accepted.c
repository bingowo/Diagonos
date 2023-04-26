#include <stdio.h>
void itob(int n,char *s,int r)//把数据n转化为r进制的函数
{
    const char table[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};//把键盘数据放入一个结构里(静态)
    int sigh=1,m=1;
    if(n<0)
    {
        sigh=-1;
        n=-n;
    }  //把负数变为正数
    *s=table[n%r];
    n=n/r;
    while(n)
    {
        *(s+m)=table[n%r];
        n=n/r;
        m+=1;
    }//一步步求余转化为r进制
    if(sigh==-1)
    {
        *(s+m)='-'; //m的值不是1
        *(s+m+1)=0;//0即为'\0'
        for(int i=0;i<m/2+1;i++)
        {
            int temp=*(s+i);*(s+i)=*(s+m-i);*(s+m-i)=temp;
        }//for循环调转s
    }
    else
    {
        *(s+m)=0;
        for(int i=0;i<m/2;i++)
        {
            int temp=*(s+i);*(s+i)=*(s+m-i-1);*(s+m-i-1)=temp;
        }
    }
}
int main()
{
    int t;//t为测试数据的组数
    int n,r;//n,r分别为输入的两个用来测试的数据
    char s[100],*ps;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&r);
        ps = s;
        itob(n,ps,r);
        printf("%s\n",s);
    }
    return 0;
}
