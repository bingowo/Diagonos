#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int _10toR(char a[],int n,int r)
{
    if(n<0)
//负数
    {printf("-");
     n=-n;}
    int temp,len=0;
    while(n>0)
    {
        temp=n%r;
        n=n/r;
        if(temp<10)
            a[len++]=temp+'0';
        //超过十进制 10用A表示,16用G
        else a[len++]=temp-10+'A';
    }
    //0存放最低位，len-1是最高位
    return len;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char a[100];
        int n;
        scanf("%d",&n);
        int len=_10toR(a,n,2);
        int s1=0,s2=0,temp=0,ans=0;
        for(int i=0;i<len-1;i++)
        {
            if(a[i]!=a[i+1])
            {
                 if(i==len-2)
                {
                    temp=i-s1+2;
                    ans=ans>temp?ans:temp;
                }
            }
            else
            {
                temp=i-s1+1;
                ans=ans>temp?ans:temp;
                s1=i+1;
            }

        }
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}
