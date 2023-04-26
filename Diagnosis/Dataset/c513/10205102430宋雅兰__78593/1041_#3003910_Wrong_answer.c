#include<stdio.h>
#include<string.h>
int main()
{
    char s[51];
    scanf("%s",s);
    int ans=1,max=1,flag=0;
    int l=strlen(s);
    int i=0;
    if(s[i]=='|')flag=1;
    while(i++<l)
    {
        if(flag==1&&s[i]=='-'){
            max++;
            flag=0;
        }
        else if(flag==0&&s[i]=='|'){
            max++;
            flag=1;
        }
        else max=0;
        ans=max>ans?max:ans;
    }
    printf("%d",ans);
    return 0;
}