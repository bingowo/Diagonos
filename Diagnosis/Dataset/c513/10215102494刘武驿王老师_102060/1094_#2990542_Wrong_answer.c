#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(void * a,void * b)
{
    if(strlen((char *)a)!=strlen((char *)b)) return strlen((char *)a)-strlen((char *)b);
    return strcmp((char *)a,(char *)b);
}
void minus(int *a,int *b,int len,int *res)
{
    int next=0,tmp;
    for(int i=0;i<len;i++)
            {
            if(a[999-i]+next>=b[999-i])
            {
                res[999-i]=a[999-i]+next-b[999-i];
                next=0;
            }
            else
            {
                tmp=0;
                while(a[999-i]+next<b[999-i])
                {
                    next+=10;
                    tmp++;
                }
                res[999-i]=a[999-i]+next-b[999-i];
                next=-tmp;
            }
    }
}
int main()
{
    int n;
    char s[60][100];
    scanf("%d",&n);
    char tmp=getchar();
    for(int i=0;i<n;i++) scanf("%s",s[i]);
    qsort(s,n,sizeof(s[0]),cmp);
    int a[1000],b[1000],res[1000];
    for(int i=0;i<1000;i++)
    {
        a[i]=0;
        b[i]=0;
        res[i]=0;
    }
    int len1=strlen(s[0]),len2=strlen(s[n-1]);
    for(int i=0;i<len1;i++)
    {
        a[999-i]=s[0][len1-1-i]-'0';
    }
    for(int i=0;i<len2;i++) b[999-i]=s[n-1][len2-1-i]-'0';
    int test=0;
    int len=1000;
    minus(b,a,len,res);
    for(int i=0;i<1000;i++)
    {
       if(res[i]!=0) test=1;
        if(test==1) printf("%d",res[i]);
   }
}
