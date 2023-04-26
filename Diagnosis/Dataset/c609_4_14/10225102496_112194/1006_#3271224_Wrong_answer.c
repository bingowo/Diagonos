#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int smsz(char s[])
{
    int sys=0;
    int res=0;
    char a[128]={0};
    char t[128]={0}; 
    int len=strlen(s);
    if(len!=1&&len!=2)
    {
       for(int j=0;j<len;j++)
       {
         int temp=(int)s[j];
         a[temp]++;
       }
       for(int k=0;k<128;k++)
       {
         if(a[k]>=1) sys++;
       }
       for(int l=0,cnt=2;l<len;l++)
       {
         int temp=(int)s[l];
         res=res*sys;
         if(cnt==1) cnt++;
         if(l==0) {res=res+l+1; t[temp]=1;}
         if(l==1) 
         {
          if(s[1]!=s[2]) {res=res+0;t[temp]=0;}
          else {res=res+1;cnt=-1;}
         }
         else
         {
          if(t[temp]==0) {res=res+cnt;t[temp]=cnt;}
          else {res=res+t[temp];} 
         }
         cnt++;
       }
    }
    else if(len==2)
    {
        if(s[0]==s[1]) res=3;
        if(s[0]!=s[1]) res=2;
    }
    else res=1;
    return res;
}
int main()
{
    int n;
    char s[10000];
    scanf("%d",&n);
    for(int i;i<n;i++)
    {
        scanf("%s",s);
        printf("case%d:\n%d\n",i,smsz(s));
    }
    return 0;
}