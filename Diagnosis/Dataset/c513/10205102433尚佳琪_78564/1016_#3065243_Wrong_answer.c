#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int _10toR(char a[],int n,int r)
{
/*if(n<0)
//负数
    {printf("-");
     n=-n;}*/
    int temp,len=0;
    while(n!=0)
    {
        temp=n%r;
       // printf("%d ",temp);
        n=n/r;
        if(temp<0)
        {
            temp=abs(r)+temp;
            n=n+1;
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
    scanf("%d %d",&n,&r);
    char a[100];

    int len=_10toR(a,n,r);
    for(int i=len-1;i>=0;i--)
        printf("%c",a[i]);
   // printf("%d",-10%(-3));
    return 0;
}
