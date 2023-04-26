#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[])
{
    int j=strlen(s)-1,k;
    for(k=0,j;j>k;k++,j--)
    {
        char a;
        a=s[k];s[k]=s[j];s[j]=a;
    }
}

void ito3(int n,char s[100])
{
    int a=abs(n),temp,i=0;
    int b=3;
    while(a!=0)
    {
        temp=a%b;
        s[i]=(temp>9)?(temp-10)+'A':temp+'0';
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
void add(int s[],int num)
{
    int len=strlen(s);int last=0;
    for(int i=len-num-1,j=0;i>=0&&j<6;i--,j++)
    {
        int x=s[i]+1+last;
        if(x==3) {s[i]=1;last=1;}
        else if(x==2) {s[i]=0;last=1;}
        else if(x==1) {s[i]=1;last=0;}
        else if(x==0) {s[i]=0;last=0;}
    }
}
void minus(int s[],int num)
{
    int len=strlen(s);
    for(int i=len-num-1,j=0;i>=0&&j<6;i--,j++)
    {
        int x=s[i]-1;
        if(x!=(-1)) s[i]=x;
        else s[i]=2;
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int num=0;//记录小数点后有几位
    int s[100];
    ito3(a,s);
    while(b)
    {
        if(b/3) {num++;b=b/3;}
    }
    add(s,num);
    minus(s,num);
    int i=strlen(s);int point=strlen(s)-num;
    for(;;i--)
    {
        if(s[i]!=0) break;
    }
    int condition=0;int k=0;//k用来判断此时的0打不打印，condition判断小数点前面有没有值
    for(int j=0;j<=i;j++)
    {
        if((s[j]!=0||k)&&i!=point) {printf("%d",s[j]),condition=1,k=1;}
        if(i==point&&condition) {printf(".");i--;point=-1;}
        if(i==point&&(~condition)) printf("0.");
    }
    return 0;
}
