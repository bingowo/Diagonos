#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[100];
    scanf("%s",s);
    int l=strlen(s);
    int k;
    int flag=0;
    for(k=0;k<l;k++)
    {
        if(s[k]=='.'){flag=1;break;}
    }
    long long int ans=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='0')ans=ans*3;
        else if(s[i]=='1')ans=ans*3+1;
        else if(s[i]=='2')ans=ans*3-1;
        else;
    }
    long long int p=1;
    if(flag==1)p=pow(3,l-k-1);

    if(ans<0){printf("-");ans=-ans;}
    if(ans==0)printf("0\n");
    else {if(ans/p!=0)printf("%lld ",ans/p);
    if(ans%p!=0)printf("%lld %lld\n",ans%p,p);
    }


}
