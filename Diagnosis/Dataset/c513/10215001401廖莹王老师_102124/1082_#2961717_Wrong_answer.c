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
int xiangjia(char s[550],char t[550],char re[550],int n)
{
    int i=strlen(t),j=0,m=0,k=0,l=0;
    for(i=i-1;i>=0;i--)
    {
        j=(s[i]-'0')+(t[i]-'0')+k;m=j%10;k=j/10;
        re[i]=m+'0';
    }
    j=0;m=0;
    if((re[n]-'0')>=5)
    {
        l=1;
        for(n=n-1;n>=0;n--)
        {
            j=(re[n]-'0')+l;m=j%10;l=j/10;
            re[n]=m+'0';
        }
    }
    return k+l;
}
void reverse(char s[])
{  int c,i,j;
   for(i=0,j=strlen(s)-1;i<j;i++,j--)
      c=s[i],s[i]=s[j],s[j]=c;
}
void xiangjia1(char s[550],char t[550],char re[550],int p)
{
    int i=strlen(s),j=strlen(t);
    int k=0,m=0,n=0,l=0;
    n=p;
    for(i=i-1,j=j-1;i>=0 && j>=0;i--,j--)
    {
        k=(s[i]-'0')+(t[j]-'0')+n;m=k%10;n=k/10;
        re[l]=m+'0';l++;
    }
    m=0;k=0;
    if(j>i && j>=0)
    {
        for(l=l;j>=0;j--)
        {
            k=(t[j]-'0')+n;m=k%10;n=k/10;
            re[l]=m+'0';l++;
        }
        if(n>0){re[l]=n+'0';l++;}
        re[l]='\0';
    }
    else if(i>j && i>=0)
    {
        for(l=l;i>=0;i--)
        {
            k=(s[i]-'0')+n;m=k%10;n=k/10;
            re[l]=m+'0';l++;
        }
        if(n>0){re[l]=n+'0';l++;}
        re[l]='\0';
    }
    else {if(n>0){re[l]=n+'0';l++;}
        re[l]='\0';}
        reverse(re);
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
    int k1=strlen(p1.t),k2=strlen(p2.t),p=0;
    if(k1>=k2){p3.t[k1]='\0';for(k1=k1-1;k1>=k2;k1--){p3.t[k1]=p1.t[k1];} p=xiangjia(p1.t,p2.t,p3.t,n);xiangjia1(p1.s,p2.s,p3.s,p);}
    else {p3.t[k2]='\0';for(k2=k2-1;k2>=k1;k2--){p3.t[k2]=p2.t[k2];}p=xiangjia(p2.t,p1.t,p3.t,n);xiangjia1(p1.s,p2.s,p3.s,p);}
    printf("%s"".",p3.s);
    int k3=strlen(p3.t);int o=0;
    if(k3<n){printf("%s",p3.t);for(k3=k3;k3<n;k3++)printf("0");}
    else{for(o=0;o<n;o++)printf("%c",p3.t[o]);}
    return 0;
}
