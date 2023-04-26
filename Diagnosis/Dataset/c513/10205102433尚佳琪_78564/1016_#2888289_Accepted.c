#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int _10toR(char a[],int n,int r)
{
    int temp,len=0;
    while(n!=0)
    {
        if(n>0)
        {
            temp=n%r;
            n=n/r;
        }
        else{
            temp=n%r;
            n=n/r;
            if(temp==0);
            else{
                temp=temp-r;
                n=n+1;
            }
        }
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
    int n,r;
    char a[100];
    scanf("%d %d",&n,&r);
    int len=_10toR(a,n,r);
    for(int i=len-1;i>=0;i--)
        printf("%c",a[i]);
    if(len==0)
        printf("0");
    //printf("Hello world!\n");
    return 0;
}
