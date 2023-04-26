#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *s)
{
    int j=strlen(s)-1,k;
    for(k=0,j;j>k;k++,j--)
    {
        int a;
        a=s[k];s[k]=s[j];s[j]=a;
    }
}

void ito3(int n,char *s)
{
    int a=abs(n),i=0;
    int b=3;
    while(a!=0)
    {
        s[i]=a%b+'0';
        a=a/b;
        i++;
        if(a==0) s[i]='\0';
    }
    reverse(s);
    if(n<0)
    {
        for(int j=strlen(s)+1;j>0;j--)
            s[j]=s[j-1];
        s[0]='-';
    }
}
void add(char *s,int num)
{
    int len=strlen(s);int last=0;
    if(num>=2)
    {
        int k=num;
        if((len-num)<4)
        {
            int x=len-num;
            for(int i=0;i<len;i++)
            {
                s[len+x-1-i]=s[len-1-i];
            }
            for(int i=0;i<x;i++)
            {
                s[i]='0';
            }
        }
        for(int i=len-num+1,j=0;i>=0&&j<6;i--,j++)
        {
            int x=(s[i]-'0')+1+last;
            if(x==3) {s[i]='1';last=0;}
            else if(x==4) {s[i]='1',last=1;}
            else if(x==2) {s[i]='2';last=0;}
            else if(x==1) {s[i]='1';last=0;}
            else if(x==0) {s[i]='0';last=0;}
        }
    }
    else
    {
        int k=num;
        if((len-num)<4)
        {
            int x=len-num+1;
            for(int i=0;i<len;i++)
            {
                s[len+x-1-i]=s[len-1-i];
            }
            for(int i=0;i<x;i++)
            {
                s[i]='0';
            }
        }
        len=strlen(s);
        for(int j=len;k<2;k++,j++)
        {
            s[j]='0';
        }
        len=strlen(s);
        int i=len-1;
        for(int j=0;i>=0&&j<6;i--,j++)
        {
            int x=(s[i]-'0')+1+last;
            if(x==3) {s[i]='0';last=1;}
            else if(x==4) {s[i]='1',last=1;}
            else if(x==2) {s[i]='2';last=0;}
            else if(x==1) {s[i]='1';last=0;}
            else if(x==0) {s[i]='0';last=0;}
        }
        while(last)
        {
            int x=(s[i]-'0')+1+last;
            if(x==3) {s[i]='1';last=0;}
            else if(x==4) {s[i]='1',last=1;}
            else if(x==2) {s[i]='2';last=0;}
            else if(x==1) {s[i]='1';last=0;}
            else if(x==0) {s[i]='0';last=0;}
            i--;
        }
    }
}
void minus(char *s,int num)
{
    int len=strlen(s);
    for(int i=len-num-1,j=0;i>=0&&j<6;i--,j++)
    {
        int x=(s[i]-'0')-1;
        if(x!=(-1)) s[i]=x+'0';
        else s[i]='2';
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int num=0;//记录小数点后有几位
    char s[100];
    ito3(a,s);
    while(b)
    {
        if(b/3) num++;
        b=b/3;
    }
    add(s,num);
    minus(s,num);
    int i=strlen(s);int point=strlen(s)-num;
    for(;;i--)
    {
        if(s[i-1]!='0') break;
    }
    int condition=0;int k=0;//k用来判断此时的0打不打印，condition判断小数点前面有没有值
    for(int j=0;j<i;j++)
    {
        if((s[j]!='0'||k)&&i!=point) {printf("%c",s[j]),condition=1,k=1;}
        else if(j==point&&condition) {printf(".");j--;point=-1;}
        else if(j==point&&(~condition)) {printf("0.");point=-1;}
    }
    return 0;
}
