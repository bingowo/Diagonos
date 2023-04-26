#include <stdio.h>
#include <stdlib.h>

void itob(int n,int r,char s[])//把十进制n转r进制结果存入s
{
    const char table[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int sigh=1,m=1;
    if(n<0)
    {
        sigh=-1;
        n=-n;
    }  //把负数变为正数
    s[0]=table[n%r];
    n=n/r;
    int id=0;
    while(n)
    {
        s[id+m]=table[n%r];
        n=n/r;
        m+=1;
    }//一步步求余转化为r进制
    if(sigh==-1)
    {
        s[id+m]='-';
        s[id+m+1]=0;//0即为'\0'
        for(int i=0;i<m/2+1;i++)
        {
            int t=s[id+i];
            s[id+i]=s[id+m-i];
            s[id+m-i]=t;
        }//for循环调转s
    }
    else
    {
        s[id+m]=0;
        for(int i=0;i<m/2;i++)
        {
            int t=s[id+i];
            s[id+i]=s[id+m-i-1];
            s[id+m-i-1]=t;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    int n,r;
    char rr[100];
    //char *pr;
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&r);
        //pr=rr;
        itob(n,r,rr);
        printf("%s\n",rr);
    }
    return 0;
}
