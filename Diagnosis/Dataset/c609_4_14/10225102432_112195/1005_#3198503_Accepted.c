#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        char s[50];
       scanf("%s",s);
       int ans,l;
        ans=0;
        l=strlen(s);
        for(int j=0;j<l;j++){
            if(s[j]=='-')
            ans=ans*3-1;
            else if(s[j]=='1')
             ans=ans*3+1;
            else ans=ans*3;
        }
       printf("case #%d:\n",i);
       printf("%d\n",ans);
    }
    return 0;
}
