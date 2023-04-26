#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int x,int y)
{
    if(y) return gcd(y,x%y);
    else return x;
}

void _3to10(char s[])
{
    long long ansA=0,ansB=0,ansC=1;
    int i=0;
    int len=strlen(s);
    for(; i<len; i++)
    {
        if(s[i]=='.') break;
        if(s[i]=='2') s[i]=-1;
        else if(s[i]=='1') s[i]=1;
        else if(s[i]=='0') s[i]=0;
        ansA=ansA*3+s[i];//A
    }
    i++;
    for(; i<len; i++)
    {
        if(s[i]=='2') s[i]=-1;
        else if(s[i]=='1') s[i]=1;
        else if(s[i]=='0') s[i]=0;
        ansB=ansB*3+s[i];//B
        ansC=ansC*3;//C
    }

    if(ansA>0&&ansB<0)//求和
    {
        ansA--;ansB=ansC+ansB;
    }
    else if(ansA<0&&ansB>0)
    {
        ansA++;ansB=ansC-ansB;
        if(ansA==0) ansB=-ansB;
    }

    long long x=gcd(abs(ansB),abs(ansC));//求最大公约数
    if (ansB==0) printf("%lld\n",ansA);
    else
    {
        if (ansA!=0) printf("%lld ",ansA);
        printf("%lld %lld\n",ansB/x,ansC/x);
    }


}

int main()
{
    char s[100];
    scanf("%s",&s);
    _3to10(s);

    return 0;
}
