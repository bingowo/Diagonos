#include<stdio.h>
#include<string.h>

int findfirst(char A[],int x)
{
    int i;
    for(i=0;i<strlen(A);i++)
    {
        if(A[i]==x) return i;
    }
    return -1;
}

int transform(char x)
{
    switch (x)
    {
        case '0':return 0;break;
        case '1':return 1;break;
        case '2':return -1;break;
        default:break;
    }
    return 0;
}

int main()
{
    char input[50]={'\0'},front[50]={'\0'};
    scanf("%s",input);
    int i=findfirst(input,'.'),j;
    strncpy(front,input,i);
    long long resA=0,resB=0,resC=0,weight=1;
    for(j=strlen(front)-1;j>=0;j--)
    {
        resA+=(transform(input[j])*weight);
        weight*=3;
    }
    weight=1;
    for(j=strlen(input)-1;j>i;j--)
    {
        resB+=(transform(input[j])*weight);
        weight*=3;
    }
    resC=weight;
    if(resB<0 && resA!=0)
    {
        resA--;
        resB=resC+resB;
    }
    if(resA==0 && resB==0) printf("0");
    else if(resB==0) printf("%lld",resA);
    else if(resA==0) printf("%lld",resB,resC);
    else printf("%lld %lld %lld",resA,resB,resC);
    return 0;
}