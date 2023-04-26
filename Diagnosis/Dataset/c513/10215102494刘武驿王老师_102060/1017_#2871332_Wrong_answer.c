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
    long long int ans=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(i<strlen(str)-1)
        {
        if(trans[i]==1&&(trans[i+1]<=10&&trans[i+1]!=1))
        {
            ans-=1;
            continue;
        }
        if(trans[i]==10&&(trans[i+1]<=100&&trans[i+1]>10))
            {
            ans-=10;
            continue;
        }
        if(trans[i]==100&&(trans[i+1]<=1000&&trans[i+1]>100))
        {
            ans-=100;
            continue;
        }
        }
        ans+=trans[i];

    }
    printf("%d",ans);
}
