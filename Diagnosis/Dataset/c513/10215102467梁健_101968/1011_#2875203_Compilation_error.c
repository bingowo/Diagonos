#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int res=0,m=63;
    for(int i=strlen(s)-1;i>1;i--){
        if('0'<=s[i]&&s[i]<='9')res=res+s[i]-48;
        else if('A'<=s[i]&&s[i]<='Z')res=res+s[i]-55;
    }
    char a[64];
    for(m=63;m>=0;m--){
        a[m]=
    }
    
    return 0;
}