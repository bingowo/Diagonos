#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void slo(int b,char a[],int l)
{
    for(int i=0; i<l; i++)
    {
        a[i]='0';
    }
    int cnt=2;
    while (b>0)
    {
        if (b%2==1)
            a[l+1-cnt]='1';
        cnt++;
        b=b/2;
    }
    a[l]='\0';
    printf("%s",a);
}
int main()
{
    char s[501],a[11],b[3];
    int len,x,y,num;
    scanf("%s",s);
    len=strlen(s);
    printf("0001");
    slo(len,a,10);
    if (len<4)
    {
        num=atoi(s);
        slo(num,a,10);
    }
    else
    {
        x=len/3;
        y=len%3;
        for (int i=0; i<x; i++)
        {
            b[0]=s[i*3];
            b[1]=s[i*3+1];
            b[2]=s[i*3+2];
            num=b[0]*100+b[1]*10+b[2];
            slo(num,a,10);
        }
        b[0]='\0';
        b[1]='\0';
        b[2]='\0';
        if (y!=0)
        {
            for (int j=0; j<y; j++)
            {
                b[j]=s[len-y+j];
            }
            num=atoi(b);
            if(num<=15)
                slo(num,a,4);
            else
                slo(num,a,7);
        }
    }
    return 0;
}