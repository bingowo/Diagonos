#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[101];
    scanf("%s",s);
    int flag=1,l=0;
    int y,n=0;
    int i=0;
    l=strlen(s);
    if(s[0]=='-')
        {
            flag=-1;
            l=strlen(s)-1;
        }
    int num[100];
    if(flag==-1)
    {
        for(i=0;i<l;i++)
            {
                num[i]=s[i+1]-'0';
                num[i]=-num[i];
            }
    }
    if(flag==1)
    {
        for(int i=0;i<l;i++)
            num[i]=s[i]-'0';
    }
    int carry[1000];
    while(1)
    {
        for(int i=0;i<l-1;i++)
        {
            y=num[i]%(-2);
            num[i]=num[i]/(-2);
            num[i+1]=num[i+1]+10*y;
        }
        y=num[l-1]%(-2);
        if(y==1||y==0)
            num[l-1]=num[l-1]/(-2);
            carry[n]=y;
        if(y==-1)
        {
            carry[n]=1;
            num[l-1]=1+num[l-1]/(-2);
        }
        n++;
        for(i=0;i<l;i++)
        {
            if(num[i]==0&&i<l-1)
                continue;
            if(num[i]!=0)
                break;
            if(num[i]==0&&i==l-1)
                goto print;
        }
    }
    print:for(int i=n-1;i>=0;i--)
        printf("%d",carry[i]);
    return 0;
}