#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void reverse(char*s)
{
    int i,j;
    char c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

int compare(char*s1,char*s2)
{
    int i,j;
    int lenth1=strlen(s1),lenth2=strlen(s2);
    if(lenth1>lenth2)
        return 1;
    if(lenth1<lenth2)
        return -1;
    for(i=0,j=0;i<lenth1||j<lenth2;i++,j++)
    {
        if(s1[i]>s2[j])
            return 1;
        if(s1[i]<s2[j])
            return -1;
    }
    return 0;
}

int minus(char*s1,char*s2)//s1-s2
{
    if(compare(s1,s2)==-1||s1[0]==0)
        return -1;
    reverse(s1);reverse(s2);
    int lenth1=strlen(s1),lenth2=strlen(s2);
    int lenth=strlen(s1),i;
    int s[1000]={0};
    if(lenth1>lenth2)
    {
        for(i=lenth2;i<lenth1;i++)
            s2[i]='0';
    }
    for(i=0;i<lenth;i++)
        s[i]=s1[i]-s2[i];
    for(i=0;i<lenth;i++)
    {
        if(s[i]<0)
        {
            s[i]=s[i]+10;
            s[i+1]=s[i+1]-1;
        }
    }
    for(i=lenth-1;i>=0;i--)
    {
        if(s[i]!=0)
            break;
        else
            lenth--;
    }
    lenth1=strlen(s1);
    for(i=0;i<lenth1;i++)
        s1[i]=0;
    for(i=0;i<lenth;i++)
        s1[i]=s[i]+'0';
    for(i=lenth2;i<lenth1;i++)
        s2[i]=0;
    reverse(s1);reverse(s2);
    return 0;
}


void division(char*s1,char*s2,char*s)//s1为分子，s2为分母
{
    int lenth1,lenth2,i=0,p=0;
    int c[1000]={0};
    lenth1=strlen(s1);lenth2=strlen(s2);
    for(i=0;s1[0];i++)
    {
        char s3[1000]={0};//存储调整后的分母,s存储商
        int lenth=0;
        for(i=0;i<lenth2;i++)
            s3[i]=s2[i];
        for(;i<lenth1;i++)
        {
            s3[i]='0';
            if(compare(s1,s3)==-1)
            {
                s3[i]=0;
                break;
            }
            lenth++;
        }
        while(minus(s1,s3)!=-1)
            c[lenth]++;
        if(p<lenth)
            p=lenth+1;
        lenth1=strlen(s1);lenth2=strlen(s2);
    }
    for(i=0;i<p;i++)
        s[i]=c[i]+'0';
    reverse(s);
}

void mutiply(int a,int b,char *s1,char* s2)
{
    if(s1[0]==0)
    {
        int c[1000]={0};
        int i,j,lenth1,lenth2;
        for(i=0;a>0;a=a/10,i++)
            s1[i]=a%10+'0';
        for(i=0;b>0;b=b/10,i++)
            s2[i]=b%10+'0';
        lenth1=strlen(s1);lenth2=strlen(s2);
        for(i=0;i<(lenth1+lenth2+1);i++)
            c[i]=0;
        for(i=0;i<lenth1;i++)
        {
            for(j=0;j<lenth2;j++)
                c[i+j]=c[i+j]+(s1[i]-'0')*(s2[j]-'0');
        }
        int lenth=lenth1+lenth2-1;
        for(i=0;i<(lenth+2);i++)
        {
            if(c[i]>=10)
            {
                if(i>=lenth-1)
                    lenth++;
                c[i+1]=c[i+1]+c[i]/10;
                c[i]=c[i]%10;;
            }
        }
        for(i=0;i<lenth1;i++)
            s1[i]=0;
        for(i=0;i<lenth;i++)
            s1[i]=c[i]+'0';

    }
    else
    {
        int c[1000]={0};
        int lenth1,lenth2,lenth,i,j;
        lenth2=strlen(s2);lenth1=strlen(s1);
        for(i=0;i<lenth2;i++)
            s2[i]=0;
        for(i=0;b>0;b=b/10,i++)
            s2[i]=b%10+'0';
        lenth2=strlen(s2);
        for(i=0;i<lenth1;i++)
        {
            for(j=0;j<lenth2;j++)
                c[i+j]=c[i+j]+(s1[i]-'0')*(s2[j]-'0');
        }
        lenth=lenth1+lenth2-1;
        for(i=0;i<(lenth+2);i++)
        {
            if(c[i]>=10)
            {
                if(i>=lenth-1)
                    lenth++;
                c[i+1]=c[i+1]+c[i]/10;
                c[i]=c[i]%10;
            }
        }
        for(i=0;i<lenth1;i++)
            s1[i]=0;
        for(i=0;i<lenth;i++)
            s1[i]=c[i]+'0';
    }
}

int main()
{
    int T,question_num;
    scanf("%d",&T);
    for(question_num=0;question_num<T;question_num++)
    {
        int m,n,n1,m1,n2;
        scanf("%d %d",&m,&n);
        printf("case #%d:\n",question_num);
        if(m==n||n==0||n==1||n==m-1)
        {
            if(n==1||n==m-1)
                printf("%d\n",m);
            else
                printf("1\n");
        }
        else
        {
            char s1[1000]={0},s2[1000]={0};//s1存储分子
            for(n1=n,m1=m;n1>1;n1--,m1--)
                mutiply(m1,m1-1,s1,s2);
            char s3[1000]={0},s4[1000]={0};//s3存储分母
            for(n2=n;n2>1;n2--)
                mutiply(n2,n2-1,s3,s4);
            reverse(s1);reverse(s3);
            char s[1000]={0};//存储最后除法得到的结果
            division(s1,s3,s);
            printf("%s\n",s);
        }
    }
}