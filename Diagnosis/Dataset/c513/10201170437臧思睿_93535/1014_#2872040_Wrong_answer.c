#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long int ll;

int add(char *s,int l)
{
    int r=0;//r存放进位；
    for(int i=l-1;i>=0;i--)
    {
        if((int)(*(s+i)-'0')+r==2){r=1;*(s+i)='0';}
        else if((int)(*(s+i)-'0')+r==1){r=0;*(s+i)='2';}
        else if((int)(*(s+i)-'0')+r==3){r=1;*(s+i)='1';}
        else{r=0;*(s+i)='1';}
    }
    return r;
}

void sub(char *s,int l)
{
    for(int i=0;i<l;i++)
    {
        if(*(s+i)=='0'){*(s+i)='2';}
        else if(*(s+i)=='1'){*(s+i)='0';}
        else if(*(s+i)=='2'){*(s+i)='1';}
    }
}

int main()
{
    int i=0,j;
    char s[150];
    memset(s,0,sizeof(char));
    ll a,b;
    scanf("%lld %lld",&a,&b);
    while(a)
    {
        s[i++]=a%3+'0';
        a/=3;
    }
    s[i]='\0';int le=i;
    for(j=0;j<i/2;j++)
    {
        ll temp=s[i-j-1];
        s[i-j-1]=s[j];
        s[j]=temp;
    }//到这里，十进制数被转换成了普通三进制，还没加小数点
    s[strlen(s)]='\0';
    if(add(s,strlen(s))==1)//加好了，第一位进位还不确定
    {
        for(i=strlen(s)-1;i>=0;i--)
        {
            s[i+1]=s[i];
        }
        s[0]='2';//第一位进位完成
    }
    i=strlen(s);
    for(j=0;j<(log(b))/(log(3));j++)
    {
        s[i-j]=s[i-j-1];
    }
    if(b!=1){s[strlen(s)-j-1]='.';}//add '.'，第二步完成
    s[strlen(s)]='\0';
    sub(s,strlen(s));
    s[strlen(s)]='\0';
    for(i=strlen(s);i>=le;i--)
    {
        if(s[i]=='0'){s[i]='\0';break;}
    }
    printf("%s",s);
}

