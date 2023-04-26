#include<stdio.h>
#include<string.h>

int main()
{
    int count,count1,len;
    long long int ans=0;
    char s[100];
    char *p=s;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        scanf("%s",s);
        len=strlen(s);
        while(len--)
        {
        if(*p='-')
        {
            ans=ans*3-1;
        }
        else if(*p='1')
        {
            ans=ans*3+1;
        }
        else
        {
            ans=ans*3;
        }
        p++;
        }
        printf("case #%d:\n",count1-count-1);
        printf("%lld\n",ans);
        p=s;
        ans=0;
    }

}
