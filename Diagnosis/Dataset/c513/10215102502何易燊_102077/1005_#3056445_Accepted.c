#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char s[51] = {};
        scanf("%s",s);
        int ans[160] = {};
        int maxm = 0;
        for (int j=strlen(s)-1;s[j]!='.';j--)
        {
            int mod = s[j]-'0';
            int pos = 0, x;
            while (pos<maxm||mod>0)
            {
                if (pos>maxm) x = mod*10;
                else x = mod*10+ans[pos];
                mod = x%8;
                ans[pos++] = x/8;
            }
            maxm = pos;
        }
        printf("case #%d:\n0.",i);
        for (int k=0;k<maxm;k++) printf("%d",ans[k]);
        printf("\n");
    }
    return 0;
}