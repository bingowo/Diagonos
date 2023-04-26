#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char s[100];
    int a[100]={0};
    scanf("%s",s);
    long long n=0;
    int temp=0;
    int temp2=1;
    int len=strlen(s);
    for(int i=len-1;i>=0;i--)
    {
        if(s[i]=='I')a[i]=1;
        else if(s[i]=='V')a[i]=5;
        else if(s[i]=='X')a[i]=10;
        else if(s[i]=='L')a[i]=50;
        else if(s[i]=='C')a[i]=100;
        else if(s[i]=='D')a[i]=500;
        else if(s[i]=='M')a[i]=1000;
        //else if(s[i]=='(')temp2=temp2*1000;
        //else if(s[i]==')')temp=5;
      //  printf("%d ",a[i]);

    }
    for(int i=len-1;i>=0;i--)
    {
        if(s[i]==')');//temp2=temp2*1000;
        else if(s[i]=='(')
        {
            /*n=n*temp2;
            a[i]=n*temp2;
            temp2=temp2/1000;*/
            a[i]=n*1000;
            n=n*1000;

        }
        else
        {
            if(i==len-1||s[i+1]==')')
                n=n+a[i];
            else if(a[i]<a[i+1])
            {
                n=n-a[i];
            }
            else
                n=n+a[i];
           // printf("%lld\n",n);
        }
    }
    printf("%lld",n);
    return 0;
}
