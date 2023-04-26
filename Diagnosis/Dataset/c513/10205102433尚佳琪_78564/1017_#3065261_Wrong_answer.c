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
    int temp=0,temp2=0;
    int flag=0;
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
        if(s[i]==')')flag++;
        else if(s[i]=='(')
        {
            /*n=n*temp2;
            a[i]=n*temp2;
            temp2=temp2/1000;*/
            temp2*=1000;
            if(flag==1)
            {
                a[i]=temp2;
                n=n+temp2;
            }
            flag--;
           // printf("%lld\n",n);
        }
        else
        {
            if(i==len-1||s[i+1]==')')
            {
                if(flag>=1)
                    temp2=temp2+a[i];
                else n=n+a[i];
            }
            else if(a[i]<a[i+1])
            {
                if(flag>=1)
                    temp2=temp2-a[i];
                else
                     n=n-a[i];
            }
            else
            {
                if(flag>=1)
                    temp2=temp2+a[i];
                else
                    n=n+a[i];
            }
          //  if(flag==1)
           //     temp2=temp2
          //  printf("%lld\n",temp2);
        }
    }
    printf("%lld",n);
    return 0;
}
