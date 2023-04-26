#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[10100]={0};
    int n=0,m,cnt=0;
    char c;
    while ((c=getchar())!=EOF && c!='\n')
    {
        if (isdigit(c))
        {
            cnt++;
            m=0;
            m=c-'0';
            while ((c=getchar())!=EOF && c!='\n' && isdigit(c))
                m=m*10+c-'0';
//            printf("%d\n",m);
            for (int i=0;i<m;i++)
                printf("%s",s);
            int len=strlen(s);
            for (int i=0;i<len;i++)
                s[i]=0;
            n=0;
        }
        s[n++]=c;
    }
    if (cnt==0)
        printf("%s\n",s);

    return 0;
}
