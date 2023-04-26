#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void mul2(int a[])
{
    int sum,f,temp=0;
    for(int i=0;i<1000;i++)
    {
        sum=a[i]*2;
        f=sum%10+temp;
        a[i]=f%10;
        temp=f/10+sum/10;
    }
}
void mul3(int a[])
{
    int sum,f,temp=0;
    for(int i=0;i<1000;i++)
    {
        sum=a[i]*3;
        f=sum%10+temp;
        a[i]=f%10;
        temp=f/10+sum/10;
    }
}
void print(int a[])
{
    int i;
    for(i=999;a[i]==0&&i>=0;i--);
    if(i==-1)printf("0\n");
    else
    {
        for(;i>=0;i--)
        {
            printf("%d",a[i]);
        }
        printf("\n");
    }
}
int main()
{
    char s[1001];
    int a[1000]={0};
    a[0]=1;
    scanf("%s",s);
    int len=strlen(s);
    if(len>1)
    {
        for(int i=0;i<len;i++)
        {
            if(i==0&&s[i]!=s[i+1])
                mul2(a);
            else if(i==len-1&&s[i]!=s[i-1])
                mul2(a);
            else if(i!=0&&i!=len-1)
            {
                if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
                    mul3(a);
                else if(((s[i]==s[i-1])&&(s[i]!=s[i+1]))||((s[i]!=s[i-1])&&(s[i]==s[i+1]))||((s[i]!=s[i-1])&&(s[i-1]==s[i+1])))
                    mul2(a);
            }

        }
    }
    print(a);
    return 0;


}
