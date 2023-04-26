#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char s[550];
    char t[550];
}shuru;
int quzheng(char s[550],char p[550])
{
    int i=0;
    for(i=0;s[i];i++)
    {
        if(s[i]=='.')break;
        else p[i]=s[i];
    }
    if(i==0){p[i]='0'+0;p[1]='\0';}
    else  p[i]='\0';
    return i;
}
void xiaoshu(char s[550],int j,char t[550])
{
    int i=0,k=j+1;
    for(j=j+1;s[j];j++)
    {
        t[i]=s[j];
        i++;
    }
    if(j==k){t[0]='0'+0;t[1]='\0';}
    else
    t[i]='\0';
}
void reverse(char s[])
{  int c,i,j;
   for(i=0,j=strlen(s)-1;i<j;i++,j--)
      c=s[i],s[i]=s[j],s[j]=c;
}
void xiangjian(char s[550],char t[550],char re[550])
{
    int i=strlen(s),j=strlen(t);
    int k=0,n=0,l=0;
    for(i=i-1,j=j-1;i>=0 && j>=0;i--,j--)
    {    k=(s[i]-'0')-(t[j]-'0')+n;
        if(k<0){k=k+10;n=-1;}
        else{n=0;}
        re[l]=k+'0';l++;
    }
    k=0;
   if(i>j && i>=0)
    {
        for(l=l;i>=0;i--)
        {
            k=(s[i]-'0')+n;
            if(k<0){k=k+10;n=-1;}
            else{n=0;}
            re[l]=k+'0';l++;
        }
        re[l]='\0';
    }
    for(l=l-1;l>0;l--){if(re[l]=='0')re[l]='\0';else break;}
    reverse(re);
}
int xiangjianxiao(char s[550],char t[550],char re[550])
{
    int i=strlen(s),j=strlen(t);
    int k=0,n=0,l=0,p=0,q=0;
    q=strcmp(s,t);
    if(i<j){for(p=i;p<j;p++)s[p]=0+'0';s[p]='\0';}
    else if(j<i){for(p=j;p<i;p++)t[p]='0'+0;t[p]='\0';}
    else p=i;

    for(p=p-1;p>0;p--)
    {    k=(s[p]-'0')-(t[p]-'0')+n;
        if(k<0){k=k+10;n=-1;}
        else{n=0;}
        re[l]=k+'0';l++;

    }
    if(q<0)n=n+10;
     k=(s[p]-'0')-(t[p]-'0')+n;
    if(k<0){k=k+10;}
    re[l]=k+'0';l++;
    re[l]='\0';
    reverse(re);
    return q;
}
int xiangjia(char re[550],int n)
{
    int j=0,m=0,k=0,l=0;
    if((re[n]-'0')>=5)
    {
        l=1;
        for(n=n-1;n>=0;n--)
        {
            j=(re[n]-'0')+l;m=j%10;l=j/10;
            re[n]=m+'0';
        }
    }
    return l;
}
int main()
{
    char s[550]={0},t[550]={0};
    shuru p1,p2,p3;int n=0;
    int i=0,j1=0,j2=0;
    for(i=0;i<550;i++){p1.s[i]='\0';p1.t[i]='\0';p2.s[i]='\0';p2.t[i]='\0';p3.s[i]='\0';p3.t[i]='\0';}
    scanf("%s %s %d",s,t,&n);
    j1=quzheng(s,p1.s);j2=quzheng(t,p2.s);
    xiaoshu(s,j1,p1.t);xiaoshu(t,j2,p2.t);

    int k1=strlen(p1.s),k2=strlen(p2.s),f=0,y=0;
    if(k1>k2)
    {
        xiangjian(p1.s,p2.s,p3.s);
        f=xiangjianxiao(p1.t,p2.t,p3.t);
        y=xiangjia(p3.t,n);
        if(f+y<0){char re[550]={0};char c[2]={"1"};strcpy(re,p3.s);xiangjian(re,c,p3.s);}
        printf("%s"".",p3.s);
    }
    else if(k1<k2)
    {
        xiangjian(p2.s,p1.s,p3.s);
        f=xiangjianxiao(p2.t,p1.t,p3.t);
        y=xiangjia(p3.t,n);
        if(f+y<0){char re[550]={0};char c[2]={"1"};strcpy(re,p3.s);xiangjian(re,c,p3.s);}
        printf("-""%s"".",p3.s);
    }
    else
    {int q=strcmp(p1.s,p2.s);
    if(q>=0)
    {xiangjian(p1.s,p2.s,p3.s);
      f=xiangjianxiao(p1.t,p2.t,p3.t);
      y=xiangjia(p3.t,n);
    if(f+y<0){char re[550]={0};char c[2]={"1"};strcpy(re,p3.s);xiangjian(re,c,p3.s);}
        printf("%s"".",p3.s);
    }
    else
    {xiangjian(p2.s,p1.s,p3.s);
      f=xiangjianxiao(p2.t,p1.t,p3.t);
      y=xiangjia(p3.t,n);
        if(f+y<0){char re[550]={0};char c[2]={"1"};strcpy(re,p3.s);xiangjian(re,c,p3.s);}
        printf("-""%s"".",p3.s);
    }
    }
     int k3=strlen(p3.t);int o=0;
    if(k3<n){printf("%s",p3.t);for(k3=k3;k3<n;k3++)printf("0");}
    else{for(o=0;o<n;o++)printf("%c",p3.t[o]);}

    return 0;
}
