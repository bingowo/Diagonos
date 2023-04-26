#include <stdio.h>
#include <string.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        char s[101],a[] = "-01";
        scanf("%s",s);
        int j,ans = 0;
        for(j = 0;j<strlen(s);j++)
        {
            int n;
            if(s[j]=='-') n = -1;
            else if(s[j]=='0') n = 0;
            else n = 1;
            ans = ans*3+n;
        }
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}
