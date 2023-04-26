#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    long long a=0,b=0;
    int i,j;
    for(i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            a=a*10+s[i]-'0';
        if(s[i]=='-'||s[i]=='+')
        {
            if(i>0)
                break;
        }
    }
    if(s[0]=='-')
    {
        if(a==0)
            a=1;
        a=-a;
    }
    if(s[i-1]=='i')
    {
        if(a==0)
            b=i;
        else{
            b=a;
            a=0;
        }
    }
    for(j=i+1;j<len;j++)
    {
        if(s[j]>='0'&&s[j]<='9')
            b=b*10+s[j]-'0';
        if(s[j]=='i')
        {
            if(s[j-1]=='-'||s[j-1]=='+')
                b=1;
        }
    }
    if(s[i]=='-')
        b=-b;
  //  printf("%d %d\n",a,b);
    long long p=0,q=0,r=0;
    int ans[1000]={0},k=0;
    while(a!=0||b!=0)
    {

        if(abs(a)%2==abs(b)%2)
            r=0;
        else
            r=1;
        q=(r-b-a)/2;
        p=(b-a+r)/2;
        a=p;
        b=q;
        ans[k++]=r;
    }
    if(s[0]=='0')
        printf("0");
    else{
        for(int i=k-1;i>=0;i--)
            printf("%d",ans[i]);
    }
    return 0;
}
