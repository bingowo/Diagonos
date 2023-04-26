#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    int n,a,b,i=0;
    scanf("%d %d",&a,&n);
    while(a/n!=0)
    {
        b=a%n;
        if(b<0)b=a-(a/n+1)*n;
        if(abs(n)>10)s[i++]=b+'A';
        else s[i++]=b+'0';
        if(a/n<0)a=a/n+1;
        else a/=n;
    }
    s[i]='\0';
    for(int j=strlen(s)-1;j>=0;j++)
    printf("%c",s[j]);
    return 0;
}