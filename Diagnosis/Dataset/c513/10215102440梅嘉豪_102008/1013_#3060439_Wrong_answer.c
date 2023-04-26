#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    scanf("%s",s);
    char* p=strchr(s,'.');
    int ans=0,t,b=0,c=1,pos=0;
    if(p==NULL)
    {
        for(int i=0;i<strlen(s);i++)
        {
            t=s[i]=='2'?-1:s[i]-'0';
            ans=ans*3+t;
        }
        printf("%d",ans);
    }
    else
    {
        while(s[pos]!='.')  pos++;
        for(int i=0;i<pos;i++)
        {
            t=s[i]=='2'?-1:s[i]-'0';
            ans=ans*3+t;
        }
        for(int i=strlen(s)-1;i>pos;i--)
        {
            t=s[i]=='2'?-1:s[i]-'0';
            b=b+c*t;
            c=3*c;
        }
        if(ans==0)  printf("%d %d",b,c);
        else
        {
            if((ans>0)&&(b<0))
            {
                ans--;
                b=b+c;
            }
            else if((ans<0)&&(b>0))
            {
                ans++;
                b=-(b-c);
            }
            else if((ans<0)&&(b<0)) b=-b;
            printf("%d %d %d",ans,b,c);
        }
        

    }
}