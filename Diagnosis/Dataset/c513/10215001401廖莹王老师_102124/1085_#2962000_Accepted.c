#include <stdio.h>
#include <stdlib.h>
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
int main()
{
    char s[550]={0},t[550]={0};
    while(scanf("%s %s",s,t)!=EOF)
    {
        int i=strlen(s),j=strlen(t);
        char re[550]={0};
        if(i>j){xiangjian(s,t,re);printf("%s\n",re);}
        else if(i<j){xiangjian(t,s,re);printf("-""%s\n",re);}
        else
        {int k=strcmp(s,t);
        if(k>=0){xiangjian(s,t,re);printf("%s\n",re);}
        else{xiangjian(t,s,re);printf("-""%s\n",re);}
        }
    }
    return 0;
}
