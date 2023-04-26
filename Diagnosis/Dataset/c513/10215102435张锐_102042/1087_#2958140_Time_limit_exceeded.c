#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(int *ans)
{
    int last=1;
    for(int i=999;i>=0;i--)
    {
        int temp=ans[i]+last;
        if(temp>9) ans[i]=temp-10,last=1;
        else ans[i]=temp,last=0;
    }
}
int yes(int *ans)
{
    int p;int b=1;
    for(p=0;p<1000;p++) {if(ans[p]!=0) break;}
    for(int i=p;i<999;i++)
    {
        if(ans[i]==ans[i+1]) {b=0;break;}
    }
    return b;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[1000];
        scanf("%s",s);
        int ans[1000]={0};int len=strlen(s);int jj=999;
        for(int j=len-1;j>=0;j--) ans[jj--]=s[j]-'0';
        while(1)
        {
            add(ans);
            if(yes(ans)==1) break;
        }
        int p;
        for(p=0;p<1000;p++) {if(ans[p]!=0) break;}
        printf("case #%d:\n",i);
        for(int k=p;k<1000;k++) printf("%d",ans[k]);
        printf("\n");
    }
    return 0;
}
