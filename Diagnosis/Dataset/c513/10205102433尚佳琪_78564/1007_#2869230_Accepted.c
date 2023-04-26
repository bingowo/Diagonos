#include <stdio.h>
#include <stdlib.h>
int _10to2(int a[],int n)
{
    int temp,len=0;
    while(n>0)
    {
        temp=n%2;
        n=n/2;
        a[len++]=temp;
    }
    //0存放最低位，len-1是最高位
    return len;
}
int cl(int a,int b)
{
    int cnt=0;
    while(a||b)
    {
        if(((a&1)&&(b&0))||((a&0)&&(b&1)))cnt++;
        a=a>>1;
        b=b>>1;
    }
    return cnt;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i;i<t;i++)
    {
        int n;
        int a[50];
        scanf("%d",&n);
        int len=_10to2(a,n);
        int cnt=1,max=1;
        for(int i=0;i<len;i++)
        {
            for(int j=i;j<len-1;j++)
            {
                if(a[j]!=a[j+1])cnt++;
                else break;
            }
            max=cnt>max?cnt:max;
            cnt=1;
        }
        printf("case #%d:\n%d\n",i,max);
    }
    return 0;
}
