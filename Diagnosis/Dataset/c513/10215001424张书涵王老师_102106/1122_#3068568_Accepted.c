#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int p=0;

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
    int lenth1,lenth2;
    lenth1=strlen(s1);lenth2=strlen(s2);
    if(lenth1>lenth2)
        return 1;
    if(lenth1<lenth2)
        return -1;
    int i;
    for(i=0;i<lenth1;i++)
    {
        if(s1[i]>s2[i])
            return 1;
        if(s1[i]<s2[i])
            return -1;
    }
    return 0;
}

void minus(char*s1,char*s2)//s1-s2
{
    reverse(s1);reverse(s2);
    int lenth1=strlen(s1),lenth2=strlen(s2);
    int c[1000]={0};
    int i;
    if(lenth1>lenth2)
    {
        for(i=lenth2;i<lenth1;i++)
            s2[i]='0';
    }
    for(i=0;i<lenth1;i++)
        c[i]=s1[i]-s2[i];
    int lenth=lenth1;
    for(i=0;i<lenth1;i++)
    {
        if(c[i]<0)
        {
            c[i]=c[i]+10;
            c[i+1]=c[i+1]-1;
        }
    }
    for(i=lenth1-1;i>=0;i--)
    {
        if(c[i]==0)
            lenth--;
        else
            break;
    }
    for(i=lenth2;i<lenth1;i++)
        s2[i]=0;
    reverse(s2);
    for(i=0;i<lenth1;i++)
        s1[i]=0;
    for(i=0;i<lenth;i++)
        s1[i]=c[i]+'0';
    reverse(s1);
}

int division_gaodi(char*beichushu,char*chushu,int*yushu,int*shang)//s为被除数
{
    int lenth1=0,lenth2=0,lenth=0,i=0,l=1;
    char yushu2[1000]={0};int k=0;
    while(compare(yushu2,"2333")!=-1||k==0)
    {
        k=1;
        int i;
        lenth2=strlen(chushu);
        for(i=0;i<lenth2;i++)
            chushu[i]=0;
        chushu[0]='2';chushu[1]='3';chushu[2]='3';chushu[3]='3';
        lenth=0;
        lenth1=strlen(beichushu);lenth2=strlen(chushu);
        for(i=lenth2;i<lenth1;i++)
        {
            chushu[i]='0';lenth++;
        }
        if(compare(beichushu,chushu)==-1)
        {
            chushu[lenth1-1]=0;lenth--;
        }
        while(compare(beichushu,chushu)!=-1)
        {
            minus(beichushu,chushu);
            shang[lenth]++;
        }
        if(lenth>=l)
            l=lenth;
        lenth1=strlen(beichushu);
        int lenthyu=strlen(yushu2);
        for(i=0;i<lenthyu;i++)
            yushu2[i]=0;
        for(i=0;i<lenth1;i++)
            yushu2[i]=beichushu[i];
    }
    int lenth3=strlen(yushu2);
    for(i=0;i<lenth3;i++)
        yushu[p]=10*yushu[p]+yushu2[i]-'0';
    p++;
    return l;
}

int main()
{
    int T;
    scanf("%d ",&T);
    int question_num=0,i=0;
    for(question_num=0;question_num<T;question_num++)
    {
        p=0;
        int yushu[1000]={0};
        char s[1000]={0};//s存储被除数，s2存储除数，s3存储商
        gets(s);
        while(compare(s,"2333")!=-1)
        {
            int lenth=0;
            char s2[1000]={0};
            int s3[1000]={0};
            s2[0]='2';s2[1]='3';s2[2]='3';s2[3]='3';
            lenth=division_gaodi(s,s2,yushu,s3);
            int lenth2=strlen(s);
            for(i=0;i<lenth2;i++)
                s[i]=0;
            for(i=0;i<=lenth;i++)
                s[i]=s3[i]+'0';
            for(i=0;i<=lenth;i++)
                s3[i]=0;
            reverse(s);
        }
        int lenth1=strlen(s);
        for(i=0;i<lenth1;i++)
            yushu[p]=10*yushu[p]+s[i]-'0';
        p++;
        for(i=p-1;i>=0;i--)
            printf("%d ",yushu[i]);
        printf("\n");
    }
    return 0;
}