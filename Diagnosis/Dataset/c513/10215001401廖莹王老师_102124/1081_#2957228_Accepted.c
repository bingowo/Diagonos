#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void reverse(char s[])
{  int c,i,j;
   for(i=0,j=strlen(s)-1;i<j;i++,j--)
      c=s[i],s[i]=s[j],s[j]=c;
}
void zh(char s[10],long long k)
{
    int i=0;for(i=0;k>0;i++)
    {
        s[i]=k%10+'0';k=k/10;
    }
    s[i]='\0';
    reverse(s);
}

void jisuan(char cs[1000],long long n)
{
    char cj[1000][10]={0};
    long long  l=0,i=0,j=0,k=0;
    long long g=0,p=0,q=0;
    j=strlen(cs)-1;
    for(i=j;i>=0;i--)
    {
        l=0;
        l=(cs[i]-'0')*n;
        cs[i]='\0';
        if(l==0)cj[k][0]='0'+0; else zh(cj[k],l);
        k++;
    }
    g=0;
    for(i=0;i<=j-1;i++)
    {
        int d=0;
        p=atoi(cj[i]);p=p+g;
        zh(cj[i],p);
        if(p==0){cs[q]='0'+0;g=0;}
        else
        {
        d=strlen(cj[i])-1;
        cs[q]=cj[i][d];
        cj[i][d]='\0';
        g=atoi(cj[i]);
        }
        q++;
    }
    p=atoi(cj[j]);p=p+g;zh(cj[j],p);reverse(cj[j]);strcat(cs,cj[j]);
    q=q+strlen(cj[j]);
    cs[q]='\0';
    reverse(cs);
}
void fu(int h)
{
    int n=0,m=0,i=0;
    scanf("%d %d",&n,&m);
    char cs[1000]={0};
    printf("case #%d:\n",h);
    if(m==0)printf("1""\n");
    else
    {
      zh(cs,1);
    for(i=0;i<m;i++)
    {
        jisuan(cs,n);
    }
    printf("%s\n",cs);
    }
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)fu(h);
}
