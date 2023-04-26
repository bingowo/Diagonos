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
            int pos = 0;
            ans[pos] = s[j]-'0';
            int carry = 0;
            int cnt = 0;
            do
            {
                int t = carry*10+ans[pos++];
                ans[cnt++] = t/8;
                carry = t%8;
            } while (carry>0||pos<maxm);
            maxm = cnt;
        }
        printf("case #%d:\n0.",i);
        for (int k=1;k<maxm;k++) printf("%d",ans[k]);
        printf("\n");
    }
    return 0;
}