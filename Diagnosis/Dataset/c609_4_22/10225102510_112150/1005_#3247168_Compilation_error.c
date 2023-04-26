#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
    int T;
    scanf("%d",&T);
    char s[N];
    int len,a=0,sum=0;
    for(int i=0;i<T,i++)
    {
        scanf("%s",s);
        len=strlen(s);
        for(int j=0;j<len;j++)
        {
            if(isdigit(s[j]))
            a=s[j]-'0';
            if(!isdigit(s[j]))
            a=-1;
            sum=3*sum+a;
        }
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}