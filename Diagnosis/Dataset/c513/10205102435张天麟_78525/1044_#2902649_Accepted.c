#include<stdio.h>
#include<string.h>
int main()
{
    char s[100001];
    int i,len,num=0;
    unsigned int ans=0;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='0'&&s[i+1]=='x')
        {
            int k;
            i+=2;
            if(i>=len)break;
            if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f'))k=0;
            while(k==0)
            {
                if(s[i]>='0'&&s[i]<='9')
                {
                    ans*=16;
                    ans+=s[i]-'0';
                    i++;
                }
                else if(s[i]>='a'&&s[i]<='f')
                {
                    ans*=16;
                    ans+=s[i]-'a'+10;
                    i++;
                }
                else
                {
                    printf("%u ",ans);
                    ans=0;
                    k=1;
                    num++;
                }
            }
        }
    }
    if(num==0)
    {
        printf("-1");
    }
    return 0;
}
