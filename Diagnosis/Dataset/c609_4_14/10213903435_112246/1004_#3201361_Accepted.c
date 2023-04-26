#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int a,b,i=0;
    char n[40];
    scanf("%d %s %d",&a,n,&b);
    //strupr(n);
    int k=0;
    while(n[k])
    {
        n[k]=toupper(n[k]);
        k++;
    }
    int sum=n[i]>'9'?n[i]-'A'+10:n[i]-'0';
    while(n[++i])
    {
        sum=n[i]>'9'?sum*a+(n[i]-'A'+10):sum*a+(n[i]-'0');
    }
    char num[40];
    int j=0;
    do
    {
        num[j++]=sum%b>9?sum%b-10+'A':sum%b+'0';
    }while(sum/=b);
    j--;
    for(;j>=0;--j)printf("%c",num[j]);
    //printf("\n%s\t%d",n,sum);
    return 0;
}
