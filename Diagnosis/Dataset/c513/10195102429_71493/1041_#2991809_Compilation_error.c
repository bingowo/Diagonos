#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windef.h>

int main()

{
    char s[52];
    scanf("%s",s);
    int cnt[52];
    cnt[0]=1;
    int maxn=1;
    for(int i=1;i<strlen(s);i++)
{
   if(s[i]!=s[i-1])
   {
       cnt[i] = cnt[i-1]+1;
       maxn = max(cnt[i],maxn);
    }
   else cnt[i] = 1;
}

    printf("%d\n",maxn);
    return 0;
}