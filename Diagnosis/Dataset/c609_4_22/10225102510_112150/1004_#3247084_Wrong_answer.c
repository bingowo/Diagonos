#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 100
int main()
{
    int A,B,sum=0,i=0,len=0,a,j=0;
    char s[N];
    scanf("%d",&A);
    scanf("%s",s);
    scanf("%d",&B);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(!isdigit(s[i])&&s[i]<'a')
        a=(s[i]-'A')+10;
        if(!isdigit(s[i])&&s[i]>='a')
        a=(s[i]-'a')+10;
        if(isdigit(s[i]))
        a=s[i]-'0';
        sum=A*sum+a;
    }
    char t[N];
    for(j=0;sum!=0;j++)
    {
        if(sum%B<10)
        t[j]='0'+sum%B;
        else if(sum%B>=10)
        t[j]='A'+sum%B-10;
        sum=sum/B;
    }
    int m=j-1;
    while(m>=0)
    {
        printf("%c",t[m]);
        m--;
    }
    return 0;
}
