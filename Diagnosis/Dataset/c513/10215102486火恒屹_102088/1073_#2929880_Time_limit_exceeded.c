#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void myitoa(long long num,char *str)
{
    int i=0;
    while(num)
    {
        str[i]=num%10+'0';
        i++;
        num=num/10;
    }
    for(int i=0;i<strlen(str)/2;i++)
    {
        char temp=str[i];
        str[i]=str[strlen(str)-i-1];
        str[strlen(str)-i-1]=temp;
    }
}

int notyabai(long long a)
{
    if(a%9==0) return 0;
    char num[51]={'\0'};
    myitoa(a,num);
    for(int j=0;j<strlen(num);j++)
        if(num[j]=='9') return 0;
    return 1;
}

int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long k=0;
    for(long long i=a;i<=b;i++)
        if(notyabai(i)) k++;
    printf("%lld",k);

}
