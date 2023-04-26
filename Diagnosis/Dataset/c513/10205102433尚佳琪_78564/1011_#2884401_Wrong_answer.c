#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int _16to2(char a[],int b[])
{
    int len=strlen(a);
    int cnt=0;
    int temp=0;
    for(int i=2;i<len;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
            cnt=cnt*16+a[i]-'0';
        else
            cnt=cnt*16+a[i]-'A'+10;
    }
    while(cnt)
    {
        b[temp++]=cnt&1;
        cnt=cnt>>1;
    }
    return temp;
}
int main()
{
    char s[50];
    int t[100]={0};
    scanf("%s",s);
    int len=_16to2(s,t);
    int a,b,qr=0,qi=0;
    for(int i=len-1;i>=0;i--)
    {
        a=-qr-qi+t[i];
        b=qr-qi;
        qr=a;
        qi=b;
    }
    if(qr==0&&qi!=0)
        printf("%di",qi);
    else if(qi==0&&qr!=0)
        printf("%d",qr);
    else if(qi>0)
    {
        if(qi==1)
            printf("%d+i",qr);
        else
            printf("%d+%di",qr,qi);
    }
    else if(qi<0)
    {
        if(qi==-1)
            printf("%d-i",qr);
        else
            printf("%d%di",qr,qi);
    }
    return 0;
}
