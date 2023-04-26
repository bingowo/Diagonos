#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a[5000];
    scanf("%d",&a);
    int len=strlen(a);
    int num=len/3;
    int last=len%3;
    int s[5000];
    s[0]=s[1]=s[2]=0;s[3]=1;
    int x,i,sum=4;
    for(i=0;i<num;i++)
    {
        x=a[i*3]*100+a[i*3+1]*10+a[i*3+2];
        int j=0;
        while(x)
        {
            s[13+10*(i+1)-j]=x&1;
            x>>=1;
            j++;sum++;
        }
        for(;j<=10;j++)
        {
            s[13+10*(j+1)-j]=0;
            sum++;
        }

    }
    if(last=2)
    {
        x=a[len-2]*10+a[len-1];
        int j=0;
        int max;
        if(x<16) max=4;
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
        x=a[len-1];
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
    int y=10*(i+1);
    int j=0;
    while(y)
    {
        s[13-j]=y&1;
        y>>=1;
        j++;sum++;
    }
    for(;j<10;j++)
    {
        s[13-j]=0;sum++;
    }
    for(int k=0;k<sum;k++)
    {
        printf("%d",s[k]);
    }
    return 0;
}
