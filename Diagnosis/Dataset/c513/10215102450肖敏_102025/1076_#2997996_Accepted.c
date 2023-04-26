#include <stdio.h>

int main() {
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char s[101],t[101];
        char m[6]={'{','[','(',')',']','}'};
        scanf("%s",s);
        t[0]=s[0];
        int top=0,ans,res=1;
        for(int i=1;s[i]!='\0';i++)
        {
            t[++top]=s[i];
            if(t[top]==m[0] && (t[top-1]==m[0] || t[top-1]==m[1]))
            {
                res=0;
                break;
            }
            else if(t[top]==m[1] && (t[top-1]==m[1] || t[top-1]==m[2]))
            {
                res=0;
                break;
            }
            else if(t[top]==m[2] && (t[top-1]==m[0] || t[top-1]==m[2]))
            {
                res=0;
                break;
            }
            if(t[top]==m[3] && t[top-1]==m[2])
                top-=2;
            else if(t[top]==m[4] && t[top-1]==m[1])
                top-=2;
            else if(t[top]==m[5] && t[top-1]==m[0])
                top-=2;
            if(top<-1)
            {
                res=0;
                break;
            }
        }
        if(top != -1)
            res=0;
        if(res==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
