#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[5000];
    scanf("%s",a);
    int len=strlen(a);
    int num=len/3;
    int last=len%3;
    int s[5000];
    s[0]=s[1]=s[2]=0;s[3]=1;
    int x,i,sum=4;//sum是填了几个空,x为要转为二进制的数
    for(i=0;i<num;i++)
    {
        x=(a[i*3]-'0')*100+(a[i*3+1]-'0')*10+(a[i*3+2]-'0');
        int j=0;
        while(j<10)
        {
            s[13+10*(i+1)-j]=x&1;
            x>>=1;
            j++;sum++;
        }
    }
    if(last==2)
    {
        x=(a[len-2]-'0')*10+(a[len-1]-'0');
        int j=0;
        int max;
        if(x<10) max=4;
        else max=7;
        while(x)
        {
            s[13+10*(i+1)-j]=x&1;
            x>>=1;
            j++;sum++;
        }
        for(;j<max;j++)
        {
            s[13+10*(j+1)-j]=0;sum++;
        }
    }
    if(last==1)
    {
        x=a[len-1]-'0';
        int j=0;
        int max=4;
        while(x)
        {
            s[13+10*(i+1)-j]=x&1;
            x>>=1;
            j++;sum++;
        }
        for(;j<max;j++)
        {
            s[13+10*(j+1)-j]=0;sum++;
        }
    }
    int y=len;
    int j=0;
    while(j<10)
    {
        s[13-j]=y&1;
        y>>=1;
        j++;sum++;
    }
    for(int k=0;k<sum;k++)
    {
        printf("%d",s[k]);
    }
    return 0;
}
