#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char a[50]={0},b[50]={0},z[16]={"0123456789ABCDEFG"};
    int m,n,i=0,sum=0;
    char *p=a;
    scanf("%d",&m);
    scanf("%s",&a);
    scanf("%d",&n);
    while(*p)
    {
        if(*p>='A'&&*p<='Z')
        {
            sum=sum*m+*p-'A'+10;
        }
        else if(*p>='a'&&*p<='z')
        {
            sum=sum*m+*p-'a'+10;
        }
        else
        {
            sum=sum*m+*p-'0';
        }
        p++;
    }
    if(sum==0)
    {
        printf("0");
    }
    while(sum)
    {
        b[i]=z[sum%n];
        i++;
        sum/=n;
    }
    i--;
    for(;i>=0;i--)
    {
        printf("%c",b[i]);
    }
    return 0;
}
