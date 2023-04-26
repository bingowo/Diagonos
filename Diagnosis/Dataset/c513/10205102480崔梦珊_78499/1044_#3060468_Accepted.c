#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[100000];
    long long ans=0;
    scanf("%s",s);
    int flag=0;
    int flag1=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='0'&&s[i+1]=='x')
        {
            i=i+2;
            while((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f'))
            {
                if(s[i]>='0'&&s[i]<='9')
                {
                    flag=1;
                    flag1=1;
                    ans=ans*16+s[i]-'0';
                    i++;
                }
                if(s[i]>='a'&&s[i]<='f')
                {
                    flag=1;
                    flag1=1;
                    ans=ans*16+s[i]-'a'+10;
                    i++;
                }
            }
            if(flag1==1)
            {
                printf("%lld ",ans);
                ans=0;
                flag1=0;
            }
        }
    }
    if(flag==0) printf("-1");
}
