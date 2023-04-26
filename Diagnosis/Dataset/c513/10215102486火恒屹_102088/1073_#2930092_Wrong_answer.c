#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long i;
void myitoa(long long num,char *str)
{
    int e=0;
    while(num)
    {
        str[e]=num%10+'0';
        e++;
        num=num/10;
    }
    for(int i=0;i<strlen(str)/2;i++)
    {
        char temp=str[i];
        str[i]=str[strlen(str)-i-1];
        str[strlen(str)-i-1]=temp;
    }
}

long long mypow(int a,int b)
{
    long long sum=1;
    for(int e=0;e<b;e++)
        sum=sum*a;
    return sum;
}
int notyabai(long long a)
{
    if(a%9==0) return 0;
    char num[51]={'\0'};
    myitoa(a,num);
    for(int j=0;j<strlen(num);j++)
    {
        if(num[j]=='9')
        {
            i=i+mypow(10,strlen(num)-j-1)-1;
            return 0;
        }
    }
    return 1;
}

int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long k=0;
    for(i=a;i<=b;i++)
        if(notyabai(i)) k++;
    printf("%lld",k);

}
