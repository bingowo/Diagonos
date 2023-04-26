#include <stdio.h>
#include <string.h>

long long decode(char information[]);
void Encrypt(char* keych,char *key);
long long pow(long long a, long long b);

int main()
{
    int T;char information[61];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%s",information);
        printf("case #%d",i);printf(":\n");
        printf("%lld\n",decode(information));
    }
    return 0;
}



long long decode(char information[])
{
    char target[61];long long hex[61]={0};long long sum=0;int num;int num1;
    Encrypt(target,information);
    num=strlen(target);
    if(num==1) num=2;
    num1=strlen(information);
    for(int i=0;i<strlen(information);i++)
    {
        if(information[i]==target[0]) hex[i]=1;
    }
    for(int j=1;j<strlen(information);j++)
    {
        if(information[j]==target[1]) hex[j]==0;
    }
    if(num>2)
    {
        for(int k=2;k<strlen(target);k++)
        {
            for(int l=2;l<strlen(information);l++)
            {
                if(information[l]==target[k]) hex[l]=k;
            }
        }
    }
    for(long long m=0;m<strlen(information);m++)
    {
        sum=sum+hex[m]*(long long)(pow(num,num1-1-m));
    }
    return sum;
}


void Encrypt(char* keych,char *key)
{
    keych[0]=key[0];
    int i,j=0,k=0,flag;
    for(i=0;key[i]!='\0';i++)
    {
        flag=1;
        for(k=0;k<j+1;k++)
        {
            if(key[i]==keych[k])
                flag=0;
        }
        if(flag)
        {
            j=j+1;
            keych[j]=key[i];
        }
    }
    keych[j+1]='\0';
}

long long pow(long long a,long long b)
{
    long long sum=1;
    for(int i=0;i<b;i++)
        sum=sum*a;
    return sum;
}