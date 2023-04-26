#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[60];
    int t,a[123];
    scanf("%d",&t);
    for (int i=0;i<t;i++)
    {
        scanf("%s",s);
        int l=strlen(s),k=0;\
        for (int j=0;j<123;j++)
    {
        a[j]=-1;
    }

    if(l>=2)
    {
        int i=0,n=2;
        char m=s[i++];
        a[(int)m]=1;
        m=s[i++];
        a[(int)m]=0;
        k=2;
        for (;i<l;i++)
        {
            m=s[i];
            if (a[(int)m]!=-1)
            {
                continue;
            }
            else
                {
                    a[(int)m]=n++;
                    k++;
                }
        }
    }
    else
    {
        char m=s[0];
        a[(int)m]=2;
        k=2;
    }


            int x=1,ans=0;
    for (int i=l-1;i>=0;i--)
    {
        ans=ans+x*a[(int)s[i]];
        x=x*k;
    }
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
    return 0;
}
