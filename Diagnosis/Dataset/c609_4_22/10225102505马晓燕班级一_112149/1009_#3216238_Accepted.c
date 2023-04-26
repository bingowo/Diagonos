#include <stdio.h>
#include <stdlib.h>

int getone( char a )
{
    int ret=0;
    for(int i=0;i<8;i++)
    {
        if((a & (1 << i)) == (1 << i))
            ret++;
    }
    return ret;
}
int gcd(int a ,int b)   //辗转相除法
{
    while(b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a; //最大公约数
}
int main()
{
    int n;
    scanf("%d",&n);
    char c = getchar();
    for(int i=0;i<n;i++)
    {
        int ret=0,num=0;
        while(c=getchar(), c != '\n')
        {
            ret = ret + getone(c);
            num++;
        }
        num*=8;
        int tmp = gcd(num,ret);
        ret/=tmp,num/=tmp;
        printf("%d/%d\n",ret,num);
    }
    return 0;
}
