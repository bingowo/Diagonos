#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        char s[1000];
        scanf("%s",s);
        int cnt=strlen(s);
        int m=1,n=0;
        for(int j=cnt-1;j>=0;j--)
        {
            if(s[j]=='-') n-=m;
            else if(s[j]=='0') n=n;
            else n+=m;
            m*=3;
        }
        printf("%d\n",n);
    }
    return 0;
}