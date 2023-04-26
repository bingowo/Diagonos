#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int main()
{
    char s[50];
    scanf("%s",s);
    int sign=0,i,j=0;
    long long x=0,a,b,pr,pi;
    if(s[0]=='-') j=1;
    for(i=j;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
        {
            x=x*10+(s[i]-'0');
        }
        else
        {
            if(s[i]=='+')
            {
                sign=1;
                if(j==1) a=-x;
                else a=x;
                x=0;
            }
            else if(s[i]=='-')
            {
                sign=-1;
                if(j==1) a=-x;
                else a=x;
                x=0;
            }
            else if(s[i]=='i'&& sign==0)
            {
                a=0;
                if(j==1) b=-x;
                else b=x;
                break;
            }
            else if(s[i]=='i' && sign!=0)
            {
                if(sign==1)
                {
                    if(x==0) b=1;
                    else b=x;
                }
                else if(sign==-1)
                {
                    if(x==0) b=-1;
                    else b=-x;
                }
                break;
            }
        }
    }
    if(i==strlen(s))
    {
        if(j==1) a=-x;
        else a=x;
        b=0;
    }
    char ans[100];int k=0,r;
    while(!(a==0 && b==0))
    {
        if((a&1) - (b&1) ==0) r=0;
        else r=1;
        ans[k]=(char)(r+48);
        k++;
        if(r==1)
        {
            a-=r;r--;
        }
        pr=a;pi=b;
        a=(pi-pr+r)/2;
        b=(r-pr-pi)/2;
    }
    ans[k]='\0';
    for(int m=strlen(ans)-1;m>=0;m--)
    {
        printf("%c",ans[m]);
    }
    return 0;
}
