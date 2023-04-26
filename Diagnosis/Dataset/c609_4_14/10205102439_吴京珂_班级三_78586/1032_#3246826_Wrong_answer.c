#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[55];
    scanf("%s",s);
    int n=strlen(s);
    int d=1,ans=0;
    for(int i=1; i<n; i++)
    {
        if(s[i]==s[i-1])
        {
            if(ans<d) ans=d;
            d=1;
        }
        else d++;

    }

    printf("%d\n",ans);

    return 0;
}
