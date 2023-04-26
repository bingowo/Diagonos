#include <stdio.h>
#include <stdlib.h>

long long

int main()
{
    int T,i,l;
    char s[60];
    char m[60];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",s);
        m[0]='1';
        int j=1;
        char d='0';
        while(s[j]!='\0')
        {
            int k=j-1;
            for(k=0;k<=j-1;k++)
            {
                if(s[k]==s[j])
                {
                    m[j]=m[k];
                    break;
                }
            }
            if(k==j)
            {
                if(d=='1') d='2';
                m[j]=d;
                d++;
            }
            j++;
        }
        /*r==d*/
        int r;
        if (d=='1') r=2;
        else r=d-'0';
        int f=0;
        for(l=0;l<j;l++)
        {
            int t;
            t=m[l]-'0';
            f=f*r+t;
        }
        printf("case #%d:\n",i);
        printf("%d\n",f);
    }
    return 0;
}