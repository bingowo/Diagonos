#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
    {return *(char*)a-*(char*)b;}

int main()
{
    int n; scanf("%d",&n);
    for (int t=0;t<n;t++)
    {
        char s[22] = {'0'}; scanf("%s",s+1);
        int len = strlen(s); int i,j;
        for (i=len-1;i>=0;i--)
        {
            int flag = 0;
            for (int j=len-1;j>=i;j--)
            {
                if (s[i]<s[j])
                {
                    s[i]^=s[j]; s[j]^=s[i]; s[i]^=s[j];
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        qsort(&s[i+1],len-i-1,sizeof(char),cmp);
        printf("case #%d:\n%s\n",t,s[0]!='0'?s:s+1);
    }
    return 0;
}