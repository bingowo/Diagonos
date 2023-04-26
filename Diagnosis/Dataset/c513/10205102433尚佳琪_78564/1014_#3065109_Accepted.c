#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
long long gcd(long long a,long long b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
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
    int a,b;
    scanf("%d %d",&a,&b);
    int tmp=gcd(a,b);
    a=a/tmp;
    b=b/tmp;
    char p[1000];
    int len=_10toR(p,a,3);
    int i=0;
    for(i=0;i<20;i++)
    {
        if(pow(3,i)==b)
            break;
    }
    int len2=i;

    int q[100]={0},k=0,m=0,n=0;
    for(int i=0;i<len;i++)
    {
        q[k++]=(p[i]-'0'+1+m)%3;
        m=(p[i]-'0'+1+m)/3;
    }
    if(m!=0)
        q[k++]=m;
    for(int i=0;i<len;i++)
    {
        if(q[i]==0)
            q[i]=2;
        else
            q[i]=q[i]-1;
    }
    if(a==0)
        printf("0");
    else if(i==0)
        for(int j=k-1;j>=0;j--)
        {
            printf("%d",q[j]);
        }
    else
        {
            if(k>len2)
                for(int j=k-1;j>=0;j--)
                {
                    if(j==(len2-1))
                        printf(".");
                    printf("%d",q[j]);
                }
            else
            {
                for(int j=k;j<len2;j++)
                {
                    q[k++]=0;
                }
                printf("0.");
                for(int j=k-1;j>=0;j--)
                {
                    printf("%d",q[j]);
                }
            }

        }
    return 0;
}
