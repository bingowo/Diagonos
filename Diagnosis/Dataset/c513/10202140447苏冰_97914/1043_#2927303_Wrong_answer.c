#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int T;
    scanf("%d",&T);
    char s[110];
    for(int cas=0;cas<T;cas++)
    {
        scanf("%s",s);
        char* p=s,*q=s;
        char t[110]={0};
        int k=0;int cnt=0;
        while(*p)
        {
            if(*p==*q)
            {
                p++;cnt++;
                if(*p=='\0' && cnt==1)
                {
                    t[k]=*q;k++;
                }
            }
            else
            {
                if(cnt==1)
                {
                    t[k]=*q;k++;
                }
                cnt=0;q=p;
            }
        }
        int ans=0;
        if(k==0) ans=1;
        else if(k<=2) ans=2;
        else
        {
            q=t;p=t+2;
            while(*p)
            {
                if(*q==*p)
                {
                    p+=2;
                }
                else
                {
                    q++;p=q+2;
                }
            }
            ans=p-q;
        }
        printf("case #%d:\n",cas);
        printf("%d\n",ans+strlen(s)-k);
    }
    return 0;
}
