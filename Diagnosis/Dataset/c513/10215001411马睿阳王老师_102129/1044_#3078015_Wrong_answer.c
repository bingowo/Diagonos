#include<stdio.h>
#include<string.h>

int main()
{
    char s[100008];
    int i,num,k=0;
    int ans[100008];
    scanf("%s",s);
    int l=strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i]=='0'&&s[i+1]=='x')
        {
            for(i+=2,num=0;(s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f');i++)
            {
                if(s[i]>='0'&&s[i]<='9')  num++,ans[k]=ans[k]*16+s[i]-'0';
                else if(s[i]>='a'&&s[i]<='f') num++,ans[k]=ans[k]*16+s[i]-'a'+10;
            } 
            if(num) k++;
        }
    }
    if(k==0) printf("-1");
    else
    {
        for(i=0;i<k;i++)
            printf("%d ",ans[i]);
    }
    return 0;
}