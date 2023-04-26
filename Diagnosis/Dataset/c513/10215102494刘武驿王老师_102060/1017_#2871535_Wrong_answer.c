#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    scanf("%s",str);
    int trans[100];
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='I') trans[i]=1;
        if(str[i]=='V') trans[i]=5;
        if(str[i]=='X') trans[i]=10;
        if(str[i]=='L') trans[i]=50;
        if(str[i]=='C') trans[i]=100;
        if(str[i]=='D') trans[i]=500;
        if(str[i]=='M') trans[i]=1000;
        if(str[i]=='(') trans[i]=-1;
        if(str[i]==')') trans[i]=-2;
    }
    long long int ans=0,tmp=0;
    int flag=0,max,test;
    for(int i=0;i<strlen(str);i++)
    {

        if(trans[i]==-1)
        {
            if(flag==0) tmp=0;

            flag+=1;
            test=1;
            continue;
        }
        if(trans[i]==-2)
        {
            if(test==1) max=flag;
            test=0;
            flag-=1;
            if(flag==0)
            {
                ans+=tmp*pow(10,max);
            }
            continue;
        }
        if(flag!=0)
        {
        if(trans[i+1]!=-2)
        {
        if(trans[i]==1&&(trans[i+1]<=10&&trans[i+1]!=1))
        {
            tmp-=1;
            continue;
        }
        if(trans[i]==10&&(trans[i+1]<=100&&trans[i+1]>10))
            {
            tmp-=10;
            continue;
        }
        if(trans[i]==100&&(trans[i+1]<=1000&&trans[i+1]>100))
        {
            tmp-=100;
            continue;
        }
        }
        tmp+=trans[i];
        }
        if(flag==0)
        {
        if(i<strlen(str)-1)
        {
        if(trans[i]==1&&(((trans[i+1]<=10&&trans[i+1]!=1)||trans[i+1]==-2)))
        {
            ans-=1;
            continue;
        }
        if(trans[i]==10&&((trans[i+1]<=100&&trans[i+1]>10||trans[i+1]==-2)))
            {
            ans-=10;
            continue;
        }
        if(trans[i]==100&&((trans[i+1]<=1000&&trans[i+1]>100||trans[i+1]==-2)))
        {
            ans-=100;
            continue;
        }
        }
        ans+=trans[i];
        }

    }
    printf("%d",ans);
}
