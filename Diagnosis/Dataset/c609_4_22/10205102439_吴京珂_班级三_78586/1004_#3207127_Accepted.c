#include <stdio.h>
#include <stdlib.h>

int Rto10(char a[],int r)
{
    int len,i,num;
    int sum=0;
    len=strlen(a);
    for(i=0; i<len; i++)
    {
        if(a[i]>='0'&&a[i]<='9') num=a[i]-'0';
        else if(a[i]>='a'&&a[i]<='f') num=a[i]-'a'+10;
        else if(a[i]>='A'&&a[i]<='F') num=a[i]-'A'+10;
        sum=sum*r+num;
    }
    return sum;
}

void _10toR(int n,int r)
{
    if(n<0)//负数
    {
        n=-n;
        printf("-");
    }

    int a[100]= {0};
    int i=0,j=0;
    if(n==0)
    {
        printf("0\n");
    }
    else
    {
        while(n!=0)
        {
            a[i]=n%r;
            n/=r;
            i++;
        }

        for(j=i-1; j>=0; j--)
        {
            if(a[j]>9) printf("%c",a[j]+55);
            else printf("%d",a[j]);
        }
        printf("\n");
    }
}

int main()
{
    int a,b;
    char s[100];
    scanf("%d %s %d",&a,&s,&b);
    //%c 输入单个字符 ; %s 输入字符串
    int n;
    n=Rto10(s,a);
    _10toR(n,b);
    return 0;
}
