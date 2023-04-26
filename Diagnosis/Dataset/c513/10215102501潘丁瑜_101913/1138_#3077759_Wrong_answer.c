#include <stdio.h>
#include <stdlib.h>

void print(int num)
{
    if(num<10) printf("%d",num);
    else printf("%c",num-10+'A');
}

void division(long long ans,int b)
{
    if(ans>0)
    {
        division(ans/b,b);
        print(ans%b);
    }
}

int main()
{
    char str[1000]={0};
    int a,b,i=0;
    scanf("%d",&a);
    scanf("%s",str);
    scanf("%d",&b);
    long long ans=0;
    while(str[i])
    {
        if(str[i] >= 'a' && str[i]<='z')
        {
            ans = ans*a+(str[i] - 'a' + 10);
        }
        else if(str[i] >='A' && str[i] <= 'Z')
            ans = ans*a + (str[i] - 'A' +10);
        else ans = ans*a+(str[i]-'0');
        i++;
    }
    division(ans,b);
    return 0;
}
