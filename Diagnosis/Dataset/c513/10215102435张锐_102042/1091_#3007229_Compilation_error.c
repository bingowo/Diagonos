#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[20];int n;
    scanf("%s",s);
    scanf("%d",&n);
    if(n==0) ,printf("0");
    else
    {
        int len=strlen(s);int a=0,b=0;int bo=1;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='-'&&i==0) {bo=-1;continue;}
            int temp=0;
            while(isdigit(s[i])) temp=temp*10+(s[i++]-'0');
            if(s[i]!='i')
            {
                a=temp*bo;
                bo=1;
                if(s[i]=='-') bo=-1;
                temp=0;
                i++;
                if(s[i]=='i') b=1;
                else
                {
                    while(isdigit(s[i])) temp=temp*10+(s[i++]-'0');
                    b=bo*temp;
                }
    
            }
            else {a=0;b=temp*bo;}
        }
        long long int ta=a,tb=b;
        for(int i=1;i<n;i++)
        {
            long long int tta=ta,ttb=tb;
            ta=(tta*a-ttb*b);
            tb=tta*b+ttb*a;
        }
        if(tb>0) printf("%lld+%lldi",ta,tb);
        else if(tb==0) printf("%lld",ta);
        else printf("%lld%lldi",ta,tb);
    }
    
    return 0;
}
