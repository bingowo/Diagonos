#include<stdio.h>
#include<string.h>
void multi(int *a,int b,int* res,int lena,int lenres)
{
    int next=0,tmp,i;
    for(i=0;i<lena;i++)
    {
        tmp=a[lena-i-1]*b;
        tmp+=next;
        res[lenres-i-1]=tmp%10;
        next=tmp/10;
    }
}
void plus(int *a,int*b,int* res,int len)
{
    int next=0,tmp,i;
    for(i=0;i<len;i++)
    {
        tmp=a[len-i-1]+b[len-i-1]+next;
        res[len-i-1]=tmp%10;
        next=tmp/10;
    }
}
int main()
{
    char str[200];
    int n;
    scanf("%s",str);
    scanf("%d",&n);
    if(n==0) 
    {
        printf("1");
        return 0;
    }
    long long int a=0,b=0;
    int i,flag0=-1,flag1=0,flag2=0,len=strlen(str),sig1=1,sig2=1,trans;
    if(str[0]=='-') flag0=0;
    for(i=1;i<len;i++)
    {
        if(str[i]=='-'||str[i]=='+') flag1=i;
        if(str[i]=='i') flag2=i;
    }
    if(flag1!=0) for(i=flag1-1;i>=flag0+1;i--) a+=pow(10,flag1-i-1)*(str[i]-'0');
    if(flag1!=0&&flag2!=0) for(i=flag2-1;i>flag1;i--) b+=pow(10,flag2-i-1)*(str[i]-'0');
    if(flag2==flag1+1) b=1;
    if(str[flag1]=='-') b=-b;
    if(str[0]=='-') a=-a;
    if(flag1==0&&flag2==0)
    {
        i--;
        for(int j=i;j>=flag0+1;j--)
        {
            trans=pow(10,i-j);
            a+=trans*(str[j]-'0');
        }
        if(flag0==0) a=-a;
    }
    if(flag1==0&&flag2!=0)
    {
        for(i=flag2-1;i>=flag0+1;i--) b+=pow(10,flag2-i-1)*(str[i]-'0');
        if(flag0==0) b=-b;
        if(flag2==flag0+1) b=-1;
    }
    if(str[0]=='i')
    {
        b=1;
        a=0;
    }
    if(str[0]=='0')
    {
        printf("0");
        return 0;
    }
    long long tmpa,tmpb,mema=a,memb=b;
    for(int i=1;i<n;i++)
    {
        tmpa=a*mema-b*memb;
        tmpb=a*memb+b*mema;
        a=tmpa;
        b=tmpb;
    }
    if(a!=0) printf("%lld",a);
    if(b<0) printf("%lldi",b);
    if(b>0&&b!=1) printf("+%lldi",b);
    if(b==1) printf("+i");
}


