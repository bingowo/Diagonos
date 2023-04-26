#include<stdio.h>
#include<string.h>

int main()
{
    char s[10001]={0};
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int flag=0;
        int cnt=0;
        char ss[10001]={0};
        while(s[i]>='a'&&s[i]<='z')
        {
            ss[cnt]=s[i];
            i++;
            cnt++;
        }
        while(s[i]>='0'&&s[i]<='9')
        {
            flag=flag*10+s[i]-'0';
            i++;
        }
        i--;
        if(flag==0) printf("%s",ss);
        for(int k=0;k<flag;k++)
        {
            printf("%s",ss);
        }
    }
}
