#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is(long long int num)
{
    char a[100]= {"\0"};
    ltoa(num,a,10);
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
        ltoa(num,a,10);
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
