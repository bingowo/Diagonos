#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[10001];
    scanf("%s",s);
    int len= strlen(s);
    char a[10001];
    int k=0;
    long long sum=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='0'&&s[i+1]=='x')
            continue;
        else if(s[i]>='0'&&s[i]<='9'||s[i]>='a'&&s[i]<='f'||s[i]>='A'&&s[i]<='F')
            a[k++]=s[i];
    }
    int len1= strlen(a);
    for(int j=0;j<len1;j++)
    {
        if(a[j]>='0'&&a[j]<='9')
            sum=sum*16+a[j]-'0';
        if(a[j]>='a'&&a[j]<='f')
            sum=sum*16+a[j]-'a'+10;
        if(a[j]>='A'&&a[j]<='F')
            sum=sum*16+a[j]-'A'+10;
    }
    if(len1==0)
        printf("%d",-1);
    else
        printf("%lld",sum);
    return 0;

}