#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void)
{
    int t=0,n=0,sz=0;
    long long int sum=0;
    char s[10000];//输入字符串
    scanf("%d\n",&t);
    for(;n<t;n++)
    {
        scanf("%s",s);
    }
    sz=strlen(s);
    for(int i=0;i<sz;i++)
    {
        if(s[i]=='-')
        {
            s[i]=-1;
        }
        sum+=s[i]*3^(sz-i-1);
        printf("case #%d:\n",i);
        printf("%lld\n",sum);
    }
    return 0;
}