#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
     char s[40];
     scanf("%s",s);
     int ans=0;
     int flag=0;
     int j=0;
     char t;
     while(j<strlen(s))
    {
        if(s[j]=='.')
        {
            break;
        }
        else if(s[j]=='2')
        {
            t='1';
            flag=-1;
        }
        else
        {
            t=s[j];
            flag=1;
        }
        ans=ans*3+flag*(t-'0');
        j++;

    }
    j++;
    int ans1=0,ans2=1;
    while(j<strlen(s))
    {
        if(s[j]=='2')
        {
            t='1';
            flag=-1;
        }
        else
        {
            t=s[j];
            flag=1;
        }
        ans1=ans1*3+flag*(t-'0');
        ans2=ans2*3;
        j++;
    }
    int go=gcd(abs(ans1),ans2);
    ans1/=go;
    ans2/=go;
    if(ans<0 && ans1>0)
    {
        ans++;
        ans1=ans2-ans1;
    }
    else if(ans>0 && ans1<0)
    {
        ans--;
        ans1=ans2+ans1;
    }
     if(ans==0)
    {
        printf("%d %d",ans1,ans2);
    }
    else if(ans1==0)
    {
        printf("%d",ans);
    }
    else
    {
        printf("%d %d %d",ans,ans1,ans2);
    }
     return 0;
}
