#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(void * a,void * b)
{
    if(strlen((char *)a)!=strlen((char *)b)) return strlen((char *)a)-strlen((char *)b);
    return strcmp((char *)a,(char *)b);
}
void plus(int *a,int*b,int* res,int len)
{
    int tmp,i,next=0;
    for(i=0;i<len;i++)
    {
        tmp=a[len-i-1]+b[len-i-1]+next;
        res[len-i-1]=tmp%10;
        next=tmp/10;
    }
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
    char s[60][1000];
    scanf("%d",&n);
    char tmp=getchar();
    for(int i=0;i<n;i++) scanf("%s",s[i]);
    char pos[60][1000],minu[60][1000];
    int count1=0,count2=0;
    for(int i=0;i<n;i++)
    {
        if(s[i][0]=='-')
        {
            for(int j=1;j<strlen(s[i]);j++) minu[count2][j-1]=s[i][j];
            minu[count2][strlen(s[i])-1]='\0';
            count2++;
        }
        else strcpy(pos[count1++],s[i]);
    }
    qsort(pos,count1,sizeof(pos[0]),cmp);
    qsort(minu,count2,sizeof(minu[0]),cmp);
    if(count2==0)
    {
        int a[1000],b[1000],res[1000];
        for(int i=0;i<1000;i++)
        {
            a[i]=0;
            b[i]=0;
            res[i]=0;
        }
        int len1=strlen(pos[0]),len2=strlen(pos[count1-1]);
        for(int i=0;i<len1;i++)
        {
            a[999-i]=pos[0][len1-1-i]-'0';
        }
        for(int i=0;i<len2;i++) b[999-i]=pos[count1-1][len2-1-i]-'0';
        int test=0;
        int len=1000;
        minus(b,a,len,res);
        for(int i=0;i<1000;i++)
        {
            if(res[i]!=0) test=1;
            if(test==1) printf("%d",res[i]);
        }
    }
    if(count1==0)
    {
        int a[1000],b[1000],res[1000];
        for(int i=0;i<1000;i++)
        {
            a[i]=0;
            b[i]=0;
            res[i]=0;
        }
        int len1=strlen(minu[0]),len2=strlen(minu[count2-1]);
        for(int i=0;i<len1;i++)
        {
            a[999-i]=minu[0][len1-1-i]-'0';
        }
        for(int i=0;i<len2;i++) b[999-i]=minu[count2-1][len2-1-i]-'0';
        int test=0;
        int len=1000;
        minus(b,a,len,res);
        for(int i=0;i<1000;i++)
        {
            if(res[i]!=0) test=1;
            if(test==1) printf("%d",res[i]);
        }
    }
    if(count1!=0&&count2!=0)
    {
        int a[1000],b[1000],res[1000];
        for(int i=0;i<1000;i++)
        {
            a[i]=0;
            b[i]=0;
            res[i]=0;
        }
        int len1=strlen(pos[count1-1]),len2=strlen(minu[count2-1]);
        for(int i=0;i<len1;i++) a[999-i]=pos[count1-1][len1-1-i]-'0';
        for(int i=0;i<len2;i++) b[999-i]=minu[count2-1][len2-1-i]-'0';
        int len=1000;
        plus(b,a,res,len);
        int test=0;
        for(int i=0;i<1000;i++)
        {
            if(res[i]!=0) test=1;
            if(test==1) printf("%d",res[i]);
        }
    }
    }