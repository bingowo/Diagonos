#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[55];
    scanf("%s",s);
    int n=strlen(s);
    int d=1,ans=1;
    for(int i=1; i<n; i++)
    {
        if(s[i]==s[i-1]) d=1;
        else d++;
        if(ans<d) ans=d;

    }

    printf("%d\n",ans);

    return 0;
}
