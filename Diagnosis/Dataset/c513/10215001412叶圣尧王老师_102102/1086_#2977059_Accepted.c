#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
char c[1001]={0};
void input(int a[])
{
    char s[502];int len,k,i;
    scanf("%s",s);len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]=='.'){k=i;break;}
    if(i==len)
        for(i=0;i<len;i++)a[501-len+i]=s[i]-'0';
    else
    {
        for(i=0;i<k;i++)
            a[501-k+i]=s[i]-'0';
        for(i=k+1;i<len;i++)
            a[500+i-k]=s[i]-'0';
    }
}

void mini(int *a,int*b)
{
    int d=0,k1=500,k2=500,i;
    for(i=1000;i>=501;i--)if(a[i]!=0){k1=i;break;}
    for(i=1000;i>=501;i--)if(b[i]!=0){k2=i;break;}
    if(k1<k2)
    {
        a[k1]--;for(i=k1+1;i<k2;i++)a[i]=9;a[k2]=10;
    }
    for(i=1000;i>=0;i--)
    {
        int t=a[i]-b[i]-d+10;
        c[i]=t%10;
        d=1-t/10;
    }
}

void output(int d)
{
    int i=1,j;
    if(c[d+501]>4)
    {
        for(j=d;;j--)
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
    int a[1001]={0},b[1001]={0},i,d;
    input(a);input(b);
    for(i=0;i<=1001;i++)
        if(a[i]!=b[i])
        {
            if(a[i]>b[i]){mini(a,b);break;}
            else
            {mini(b,a);printf("-");break;}
        }
    scanf("%d",&d);
     output(d);
}
