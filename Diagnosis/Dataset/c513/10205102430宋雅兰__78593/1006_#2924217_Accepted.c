#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int T,m,ans,l;
    scanf("%d",&T);
    for(m=0;m<T;m++){
        char s[10001];
        scanf("%s",s);
        l=strlen(s);
        ans=0;
        int j;
        for(j=0;j<l-1;j++){
            if(s[j]=='-')ans+=-1;
            if(s[j]=='0')ans+=0;
            if(s[j]=='1')ans+=1;
            ans*=3;
        }
        if(s[j]=='-')ans+=-1;
            if(s[j]=='0')ans+=0;
            if(s[j]=='1')ans+=1;
        printf("case #%d:\n%d\n",m,ans);
    }
}