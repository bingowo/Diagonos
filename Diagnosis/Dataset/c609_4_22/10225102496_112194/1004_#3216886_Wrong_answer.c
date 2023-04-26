#include<stdlib.h>
#include<stdio.h>

int main()
{
    char t[16]={"0123456789ABCDEf"};
    int A,B,i,j;
    int temp=0;
    char s[32];
    scanf("%d%s%d",&A,s,&B);
    for(i=0;s[i];i++)
        temp+=s[i]*A;
    for(;temp>0;)
    {
        printf("%c",t[temp%B]);
        temp=temp/B;
    }
    return 0;
}
