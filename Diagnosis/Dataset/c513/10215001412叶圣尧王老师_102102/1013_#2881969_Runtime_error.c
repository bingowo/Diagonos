#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char str1[30],str2[30];int dot,i,j,k,len;long long num=0,B=1,C=0;
    scanf("%s",str1);
    dot=strchr(str1,'.');
    if(dot==NULL){
    for(i=0;i<strlen(str1);i++)
    {
        if(str1[i]=='2')k=-1;
        else k=str1[i]-'0';
        num=num*3+k;
    }printf("%lld",num);}
    else
    {
        len=dot-1;num=0;
        for(i=0;i<len;i++)
        {
            if(str1[i]=='2')k=-1;
            else k=str1[i]-'0';
            num=num*3+k;
        }printf("%lld ",num);
        for(j=dot;j<strlen(str1);j++)
        {
            if(str1[i]=='2')k=-1;
            else k=str1[i]-'0';
            B=B*3;C=3*C+k;
        }
        printf("%lld %lld",C,B);
    }
}