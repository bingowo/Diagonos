#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int primes[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};

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

int main()
{
       char s1[100];
       int num1[26];
       long long int weight=1,ans=0;
       memset(num1,-1,sizeof(num1));
       scanf("%s",s1);
       readnum(s1,num1);

       for(int i=25;num1[i]!=-1;i--)
       {
           ans=ans+weight*num1[i];
           weight=weight*primes[i];
       }
       printf("%lld",ans);
   return 0;
}

