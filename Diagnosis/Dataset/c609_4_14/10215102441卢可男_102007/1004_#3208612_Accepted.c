#include <stdio.h>
#include <stdlib.h>
int A_to_ten(int a,char*s )//a为进制
{
    int i=0,res=0,tem;
    while(s[i])
    {
        if('0'<=s[i]&&s[i]<='9')
            tem=s[i]-'0';
        else if('a'<=s[i]&&s[i]<='f')
            tem=s[i]-'a'+10;
        else
            tem=s[i]-'A'+10;

        res=(res+tem)*a;
        i++;

    }
    res/=a;//多乘了一项
    return res;

}
int  ten_to_B(char*a,long long n,int b)
{
    int i=0,m;
    while(n)
    {

       m=n%b;
       if(m<10)
        a[i]=m+'0';
       else
        a[i]=m+'A'-10;
       n/=b;
       i++;
    }
    return i;

}
int main()
{
    int a,b,i;
    char s[100]={0};
    char r[100]={0};
    scanf("%d%s%d",&a,s,&b);
    if(strlen(s)==1&&s[0]=='0')
    {
        printf("0\n");
    }
    else
    {
        int len,res;
        res=A_to_ten(a,s);
        len=ten_to_B(r,res,b);
        for(i=len-1;i>=0;i--)
        {
            printf("%c",r[i]);
        }
    }


}
