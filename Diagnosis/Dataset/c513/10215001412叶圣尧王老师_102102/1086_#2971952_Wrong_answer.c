#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int c[1001]={0};
int input(int a[])
{
    char s[502];int len,k,i,m;
    scanf("%s",s);len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]=='.'){k=i;break;}
    if(i==len)
        for(i=0;i<len;i++){a[501-len+i]=s[i]-'0';m=1;}
    else
    {
        for(i=0;i<k;i++)
            a[501-k+i]=s[i]-'0';
        for(i=k+1;i<len;i++)
            a[500+i-k]=s[i]-'0';
        m=len-k-1;
    }
    return m;
}

void mini(int *a,int*b,int k1,int k2)
{
    int d=0,flag=1;
    if(k1>k2)flag=1;
    if(k1<k2)flag=-1;
    if(k1==k2)for(int i=501;i<=500+k1;i++)if(a[i]<b[i]){flag=-1;break;}
    if(flag==1){
    for(int i=1000;i>=0;i--)
    {
        int t=a[i]-b[i]-d+10;
        c[i]=t%10;
        d=1-t/10;
    }}
    if(flag==-1)
    {

        for(int i=1000;i>=501;i--)
        {
            int t=b[i]-a[i]-d+10;
            c[i]=t%10;
            d=1-t/10;
        }
        for(int i=500;i>=0;i--)
        {
            int t=a[i]-b[i]-d+10;
            c[i]=t%10;
            d=1-t/10;
        }
    }
}

void output(int d)
{
    int i=1,j;
    if(c[d+500]>4)
    {
        for(j=d;j>0;j--)
        {
            int t=c[j+500]+1;
            c[j+500]=t%10;
            if(t/10==0)break;
        }
    }
    while(c[i]==0&&i<=499)i++;
    for(;i<=500;i++)printf("%d",c[i]);printf(".");
    for(;i<=500+d;i++)printf("%d",c[i]);
}
int main()
{
    int a[1001]={0},b[1001]={0},i,d,k1,k2;
    k1=input(a);k2=input(b);
    for(i=0;i<=1001;i++)
        if(a[i]!=b[i])
        {
            if(a[i]>b[i]){mini(a,b,k1,k2);break;}
            else
            {mini(b,a,k2,k1);printf("-");break;}
        }
    scanf("%d",&d);
     output(d);
}

