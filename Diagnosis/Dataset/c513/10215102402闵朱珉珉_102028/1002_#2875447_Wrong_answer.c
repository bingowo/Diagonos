#include <stdio.h>
#include <string.h>
int main()
{
    int a[123],i,T,j,len,q=0;
    unsigned long long int res;
    char s[60];
    scanf("%d",&T);
    for (int k=0;k<123;k++) {a[k]=-1;}
    for (int k=0;k<T;k++)
    {
        scanf("%s",&s);
        res=0;i=1;j=2;
        a[s[0]]=1;
        for (len=strlen(s);len>0;len--)
        {
            if (a[s[i++]]==-1) {a[s[--i]]=0;i++;break;}
        }
        i=1;
        for (int len=strlen(s);len>0;len--)
        {
            if (a[s[i++]]==-1) {a[s[--i]]=j++;i++;}
        }
        if (j>2) j--;
        for (len=0;len<strlen(s);len++) res=res*j+a[s[len]];
        printf ("case #%d:\n%u\n",q,res);
        for (int k=0;k<123;k++) {a[k]=-1;}
        q++;
    }
    return 0;
    }

