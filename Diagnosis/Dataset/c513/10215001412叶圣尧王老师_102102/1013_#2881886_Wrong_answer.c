#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char str1[30],str2[30];int dot,i,j,k,len;long long num;
    scanf("%s",str1);
    dot=strchr(str1,'.');
    len=dot-1;num=0;
    for(i=0;i<len;i++)
    {
        if(str1[i]=='2')k=-1;
        else k=str1[i]-'0';
        num=num*3+k;
    }
    printf("%lld ",num);
    for(j=strlen(str1);j>=dot;j++)
    {
        
    }
}