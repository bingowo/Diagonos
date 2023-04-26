#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void reverse(char  a[])
{
    int l=strlen(a)-1;
    int i;
    char p;
    for(i=0;i<=l/2;i++)
    {
        p=a[i];
        a[i]=a[l-i];
        a[l-i]=p;
    }
}

void minus(char a[],char b[],char ans[])
{
    int l1=strlen(a);
    int l2=strlen(b);
    int len=l1>l2?l1:l2;
    int i,j;
    for(i=0;i<len;i++) ans[i]=a[i]-b[i]+'0';
    for(i=0;i<len;i++)
    {
        if(ans[i]<'0')
        {
            ans[i+1]--;
            ans[i]+=10;
        }
    }
    ans[i]='\0';
}

int main()
{
    char a[1008]={0},b[1008]={0},ans[1008]={0},ans1[1008]={0},tmp[1008]={0};
    memset(a,'0',sizeof(a));
    memset(b,'0',sizeof(b));
    memset(ans,'0',sizeof(ans));
    memset(ans1,'0',sizeof(ans1));
    memset(tmp,'0',sizeof(tmp));
    int k,i,j;
    while(scanf("%s",a)!=EOF&&scanf("%s",b)!=EOF)
    {
        if(strcmp(a,b)==0)
        {
            printf("0\n");
            continue;
        }
        int l1=strlen(a);
        int l2=strlen(b);
        int len=l1>l2?l1:l2;
        if((l1<l2)||(l1==l2&&strcmp(a,b)<0))
        {
            strcpy(tmp,a);
            strcpy(a,b);
            strcpy(b,tmp);
            k=1;
            reverse(a);
            reverse(b);
            int i;
            for(i=l2;i<len;i++) a[i]='0';
            for(i=l1;i<len;i++) b[i]='0';
            a[len]='\0';b[len]='\0';
        }
        else
        {
            k=0;
            reverse(a);
            reverse(b);
            int i;
            for(i=l1;i<len;i++) a[i]='0';
            for(i=l2;i<len;i++) b[i]='0';
            a[len]='\0';b[len]='\0';
        }
        minus(a,b,ans);
        reverse(ans);
        int l=strlen(ans);
        int flag = 1;
       for(i = 0,j = 0; i < len; i++)//去掉前面多余的0
        {
           if(flag && ans[i] == '0')continue;
           flag = 0;
           ans1[j] = ans[i];
           j++;
        }
        ans1[j]='\0';
        if(k==1) printf("-%s\n",ans1);
        else if(k==0) printf("%s\n",ans1);
        memset(a,'0',sizeof(a));
        memset(b,'0',sizeof(b));
        memset(ans,'0',sizeof(ans));
        memset(ans1,'0',sizeof(ans1));
        memset(tmp,'0',sizeof(tmp));
    }
    return 0;
}
