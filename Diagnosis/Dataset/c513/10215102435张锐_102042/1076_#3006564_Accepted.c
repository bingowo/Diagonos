#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int f=0;f<t;f++)
    {
        char s[1000];
        scanf("%s",s);
        int ans[100]={0};int p=0;int bo=1;
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            char c=s[i];
            if(c=='{')
            {
                if(ans[p]==0&&p==0) ans[p]=1;
                else if(ans[p]==3||p==-1) ans[++p]=1;
                else {bo=0;break;}
            }
            else if(c=='}')
            {
                if(ans[p]==1) p--;
                else {bo=0;break;}
            }
            else if(c=='(')
            {
                if(ans[p]==0&&p==0) ans[p]=3;
                else if(ans[p]==2||p==-1) ans[++p]=3;
                else {bo=0;break;}
            }
            else if(c==')')
            {
                if(ans[p]==3) p--;
                else {bo=0;break;}
            }
            else if(c=='[')
            {
                if(ans[p]==0&&p==0) ans[p]=2;
                else if(ans[p]==1||p==-1) ans[++p]=2;
                else {bo=0;break;}
            }
            else if(c==']')
            {
                if(ans[p]==2) p--;
                else {bo=0;break;}
            }
        }
        if(bo==0) printf("No\n");
        else if(p==-1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
