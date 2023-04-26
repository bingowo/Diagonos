#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[50];
    scanf("%s",s);
    int cnt[50] = {1} , ans = 1;
    for( int i = 1 ; i < strlen(s) ; i++)
    {
        if( s[i-1] != s[i] )
        {
            cnt[i] = cnt[i-1] + 1;
            ans = ans > cnt[i] ? ans : cnt[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
