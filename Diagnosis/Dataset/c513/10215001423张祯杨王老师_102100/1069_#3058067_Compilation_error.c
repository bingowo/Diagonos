#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* l2a(long long num, char *str)
{
    int i = 0;
    if(num<0)
    {
        num = -num;
        str[i++] = '-';
    }
    do
    {
        str[i++] = num%10+48;
        num /= 10;
    }
    while(num);
    str[i] = '\0';
    int j = 0;
    if(str[0]=='-')
    {
        j = 1;
        i++;
    }
    for(; j<i/2; j++)
    {
          str[j] = str[j] + str[i-1-j];
        str[i-1-j] = str[j] - str[i-1-j];
        str[j] = str[j] - str[i-1-j];
    }

    return str;
    int is(long long int num)
{
    char a[100]= {"\0"};
    l2a(num,a);
    int len=strlen(a), flag=1;
    for(int i=0; i<=len/2; i++)
    {
        if(a[i]!=a[len-i-1])
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int main()
{
    long long int num;
    int cnt=0;
    scanf("%lld",&num);
    while(is(num)==0)
    {
        char a[100]= {"\0"};
        l2a(num,a);
        int len=strlen(a);
        char b[len];
        for(int i=0; i<len; i++)
            b[i]=a[len-i-1];
        long long int tmp=atoi(b);
        num+=tmp;
        cnt++;
    }
    printf("%d %lld", cnt, num);


}



