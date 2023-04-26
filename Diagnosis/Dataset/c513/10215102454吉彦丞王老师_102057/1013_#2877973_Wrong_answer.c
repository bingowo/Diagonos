#include<stdio.h>
#include<string.h>
long long int zhishu(int a)
{
    int b=1;
    for(int i=0;i<a;i++)
    {
        b=b*3;
    }
    return b;
}
int main()
{
    char s[30];
    scanf("%s",&s);
    int l=strlen(s);
    int a[l];
    int d=1;
    long long int result=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]!='.')
        {
            d++;
        }
        if(d==l)
        {
            for(int j=0;j<d;j++)
            {
                if(s[j]=='1')
                {
                    a[j]=1;
                }
                else if(s[j]=='0')
                {
                    a[j]=0;
                }
                else
                {
                    a[j]=-1;
                }
            }
            for(int k=0;k<l;k++)
            {
                result=result+a[k]*zhishu(l-k-1);
            }
        }
        else
        {
            
        }
    }
    printf("%lld",result);
}