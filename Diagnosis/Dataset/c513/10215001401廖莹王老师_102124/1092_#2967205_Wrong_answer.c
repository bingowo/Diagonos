#include <stdio.h>
#include <stdlib.h>
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
    long long l=0,i=0,j=0,k=0;
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
int main()
{
    char s[1000]={0};
    char re[10000]={0};
    long long p[1500]={0};
    scanf("%s",s);
    int i=0,j=strlen(s);
    for(i=0;i<j;i++)
    {
        if(i==0){p[0]=1;if(s[0]!=s[1]&& s[1])p[0]=2;}
        else if(i==j-1){p[i]=1;if(s[i]!=s[i-1])p[i]=2;}
        else
        {
            p[i]=1;
            if(s[i]!=s[i-1])p[i]++;
            if(s[i]!=s[i+1])p[i]++;
        }
    }
    re[0]=p[0]+'0';re[1]='\0';
    for(i=1;i<j;i++)
    {
        jisuan(re,p[i]);
    }
    printf("%s\n",re);
    return 0;
}

