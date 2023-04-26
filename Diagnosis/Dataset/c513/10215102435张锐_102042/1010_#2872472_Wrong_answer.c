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
    int x,i=0,sum=4;//sum是填了几个空,x为要转为二进制的数
    for(;i<num;i++)
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
        x=(a[i*3]-'0')*10+(a[i*3+1]-'0');
        int j=0;
        int max;
        if(x<10) max=4;
        else max=7;
        while(j<max)
        {
            s[13+max*(i+1)-j]=x&1;
            x>>=1;
            j++;sum++;
        }
    }
    if(last==1)
    {
        x=a[i*3]-'0';
        int j=0;
        int max=4;
        while(j<max)
        {
            s[13+max*(i+1)-j]=x&1;
            x>>=1;
            j++;sum++;
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
