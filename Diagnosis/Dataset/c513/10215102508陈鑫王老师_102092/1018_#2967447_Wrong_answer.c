#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int primes[27]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2,1};

void readnum(char s[],int num[])
{
    char* p=s;
    int index=0,temp=0;
    while(*p)

    {
        if(*p==',')
        {
            num[index++]=temp;
            temp=0;
        }
        else temp=temp*10+(*p-'0');
        p++;
    }
    num[index++]=temp;
    memmove(num+(26-index),num,sizeof(int)*index);
    memset(num,-1,sizeof(int)*(26-index));
}

void add(char s1[],char s2[],char res[])
{
    for(int i=99;i>=0;i--)
        {
            res[i]=res[i]+s1[i]+s2[i]-3*'0';
            if(res[i]>=10)
            {
                res[i]-=10;
                res[i-1]+=1;
            }
            res[i]+='0';

        }
    }

void multiply(char s1[],char s2[],char res[])
{

    int len=0;
    while(s2[len]=='0')
    {
        len++;
    }
    if(len==98)
    {
        char s21[100],s22[100],s02[100];
        char res1[100],res2[100];
        memset(s21,'0',sizeof(s21));
        memset(s22,'0',sizeof(s22));
        s21[99]=s2[99];
        s22[99]=s2[98];
        memset(res1,'0',sizeof(res1));
        memset(res2,'0',sizeof(res2));
        memmove(s02,s1+1,99);
        s02[99]='0';
        multiply(s1,s21,res1);
        multiply(s02,s22,res2);
        add(res1,res2,res);

    }
    else if(len==99)
    {
        int temp;
        for(int i=99;i>=0;i--)
        {
            temp=(s1[i]-'0')*(s2[99]-'0');
            res[i]=temp%10+'0';
            if(temp>=10)
                res[i-1]=((res[i-1]-'0')+temp/10)+'0';
        }
    }




}

void parallel(int n,char s[])
{
    for(int i=99;i>=0;i--)
    {
        s[i]=n%10+'0';
        n/=10;
    }
}
void primetodec(int num[],char res[])
{
    char s1[100],s2[100],s3[100],s4[100];
    memset(s1,'0',sizeof(s1));
    memset(s2,'0',sizeof(s2));
    memset(s3,'0',sizeof(s3));
    memset(s4,'0',sizeof(s4));
    for(int i=0;i<26;i++)
    {

        if(num[i]!=-1)
        {
            parallel(num[i],s2);
            add(s1,s2,s3);
            parallel(primes[i+1],s4);
            memset(s1,'0',sizeof(s1));
            multiply(s3,s4,s1);
            memset(s3,'0',sizeof(s3));

        }
    }
    int len=0;
    while(s1[len]=='0')
        len++;
    memmove(res,s1+len,100-len);
    res[100-len]='\0';
}


int main()
{
       char s1[100],res[100];
       int num1[26];
       memset(num1,-1,sizeof(num1));
       memset(res,'0',sizeof(res));
       scanf("%s",s1);
       if(strcmp(s1,"0")==0)
       {
           printf("0");
       }
       else
       {

       readnum(s1,num1);
       primetodec(num1,res);
       printf("%s",res);
       }


   return 0;
}

