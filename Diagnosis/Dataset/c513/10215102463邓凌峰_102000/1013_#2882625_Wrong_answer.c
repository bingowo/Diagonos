#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char num1[31]={'\0'},num2[31]={'\0'};
    char a;
    int cnt=0;
    while((a=getchar())!='.' && a!='\n'){num1[cnt++]=a;}
    int sum=0,len=strlen(num1);
    int max=pow(3,len-1);
    int i=0;
    for(;i<len;i++){
        if(num1[i]=='.'){i++;break;}
        if(num1[i]=='1') sum+=max;
        else if(num1[i]=='0');
        else sum-=max;
        max/=3;
    }
    printf("%d",sum);
    return 0;
}





