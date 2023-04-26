#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int loo(char *s1,char *s2,char *s)
{
    int i,j,be=-1,en=-1,n;
    for(i=0;i<strlen(s);i++)
    {
        j=0;
        n=0;
        while(s[i]==s1[j]&&j<strlen(s1)&&i<strlen(s))
        {
            i++;
            j++;
            n++;
        }
        if(j==strlen(s1))
            {
                be=i;
                i-=n;
                break;
            }
            i-=n;
    }
    for(i=be;i<strlen(s);i++)
    {
        j=0;
        n=0;
        if(s[i]==s2[j])
        {
            en=i;
            while(s[i]==s2[j]&&j<strlen(s2)&&i<strlen(s))
            {
                i++;
                j++;
                n++;
            }
            if(j!=strlen(s1))
                en=-1;
            i-=n;
        }
    }
    if(be==-1||en==-1)
        return 0;
    else
        return en-be;
}
int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int n1,n2;
        char s1[81],s2[81],s[81];
        gets(s1);
        gets(s2);
        gets(s);
        n1=loo(s1,s2,s);
        n2=loo(s2,s1,s);
        if(n1>n2)
            printf("%d\n",n1);
        else
            printf("%d\n",n2);
    }
    return 0;
}
