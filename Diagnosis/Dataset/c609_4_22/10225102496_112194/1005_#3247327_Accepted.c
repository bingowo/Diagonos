#include<stdio.h>
#include<string.h>

int count(char s[])
{
    int ans=0; 
    int len=strlen(s);
     for(int j=0;j<len;j++)
        {
            ans=ans*3;
            if(s[j]=='-') ans=ans-1;
            if(s[j]=='0') ans=ans+0;
            if(s[j]=='1') ans=ans+1;
        }
    return ans;
}
int main()
{
    int n;
    char s[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        printf("case #%d:\n%d\n",i,count(s));
    }
    return 0;
}