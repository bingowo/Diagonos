#include <stdio.h>
#include <string.h>
int main()
{
    int a[123],i,T,j=2;
    long long int res;
    char s[60];
    scanf("%d",&T);
    for (int k=0;k<T;k++)
    {
        scanf("%s",&s[60]);
        int len=strlen(s);
        res=0;
        a[s[0]]=1;
        for (len;len>0;len--)
        {
            if (!(a[s[i]])) a[s[i]]=j++;
        }
        for (len=strlen(s);len>0;len--) res=res*j+a[s[len]];
        printf ("%d",res);
        
    }
    return 0;
    }

