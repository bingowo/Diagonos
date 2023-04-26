#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
    {return strcmp((char*)a,(char*)b);}

int main()
{
    int n; scanf("%d",&n);
    for (int t=0;t<n;t++)
    {
        char s[22] = {}; scanf("%s",s);
        int len = strlen(s); int i;
        for (i=len-2;i>=0;i--)
        {
            if (s[i]<s[len-1]) {s[i]^=s[len-1]; s[len-1]^=s[i]; s[i]^=s[len-1]; break;}
        }
        qsort(&s[i+1],len-i-1,sizeof(char),cmp);
        printf("case #%d:\n%s\n",t,s);
    }
    return 0;
}