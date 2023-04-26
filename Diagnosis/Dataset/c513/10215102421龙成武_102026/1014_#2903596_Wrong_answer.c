#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void change3(int a,char *c)
{
    int i=0,j;
    char temp;
    while(a>=3)
    {
        c[i++]=a%3+'0';
        a/=3;
    }
    c[i++]=a+'0';
    c[i]=0;
    for(i=0,j=strlen(c)-1;i<j;i++,j--)
    {
        temp=c[i];
        c[i]=c[j];
        c[j]=temp;
    }
}
void threeplus(char *c,char *res)
{
    int i,len=strlen(c)-1,up=0,sum;
    for(i=len;i>=0;i--)
    {
        sum=(c[i]-'0')+1+up;
        if(sum>=3)
        {
            up=1;
            sum-=3;
        }
        else
        {
            up=0;
        }
        res[i]='0'+sum;
    }
}
void threeminu(char*res)
{
    int a;
    for(int i=0;i<strlen(res);i++)
    {
        a=res[i]-'0'-1;
        if(a==-1)
        {
            res[i]='2';
        }
        else
        {
            res[i]=res[i]-1;
        }
    }
}
int main()
{
    int A,B,k=-1,temp,i;
    char c[33],res[34];
    scanf("%d %d",&A,&B);
    for(temp=B;temp!=0;temp/=3)
    {
        k++;
    }
    change3(A,c);

    res[strlen(c)]=0;
    threeplus(c,res);
    threeminu(res);

    if(k>0)
    {
        temp=strlen(res);
        for(i=temp;i>=temp-k;i--)   //我这会改变字符串长度的
        {
            res[i+1]=res[i];
        }
        res[temp-k]='.';                     //加小数点的功能
    }


    puts(res);

    return 0;
}
