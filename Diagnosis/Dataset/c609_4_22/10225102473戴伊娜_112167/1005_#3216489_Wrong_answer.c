#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    int  a[50];
    char s[50];
    long long int sum;
    sum=0;
    for(int q=0;q<T;q++)
    {
        scanf("%s",s);
    for(int i=0;s[i]=='0'||s[i]=='1'||s[i]=='-';i++)
    {
        scanf("%c",&s[i]);
        if(s[i]=='1')
            a[i]=1;
        if(s[i]=='-')
            a[i]=-1;
        if(s[i]=='0')
            a[i]=0;
        sum=sum*3+a[i];
    }
    printf("case #");
    printf("%d:\n",q);
    printf("%lld\n",sum);
    }
}
