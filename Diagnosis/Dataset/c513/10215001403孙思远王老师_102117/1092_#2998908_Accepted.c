#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char x[1001];
    gets(x);
    int n=strlen(x),i,j,s[1000]={1};
    if(x[0]!=x[1])
        s[0]=2;
    for(i=1;i<n-1;i++)
    {
        if(x[i]!=x[i-1]&&x[i]!=x[i+1]&&x[i+1]!=x[i-1])
        {
            for(j=0;j<1000;j++)
                s[j]*=3;
        }
        else if(x[i]==x[i-1]&&x[i]==x[i+1]);
        else
        {
            for(j=0;j<1000;j++)
                s[j]*=2;
        }
        for(j=0;j<1000;j++)
        {
            if(s[j]>9)
            {
                s[j+1]+=s[j]/10;
                s[j]%=10;
            }
        }
    }
    if(x[n-1]!=x[n-2])
    {
            for(j=0;j<1000;j++)
                s[j]*=2;
    }
    for(i=0;i<1000;i++)
        {
            if(s[i]>9)
            {
                s[i+1]+=s[i]/10;
                s[i]%=10;
            }
        }
    for(i=999;i>=0;i--)
    {
        if(s[i]!=0)
            break;
    }
    if(n==1)
        printf("1");
    else
    {
        for(;i>=0;i--)
            printf("%d",s[i]);
    }
    return 0;
}
