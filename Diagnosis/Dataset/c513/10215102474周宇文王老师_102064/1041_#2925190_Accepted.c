#include <stdio.h>
#include <stdlib.h>
int max(a,b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }

}

int main()
{
    char s[51];
    scanf("%s",&s);
    int cnt[51];
    cnt[0] = 1;
    int maxn = 1;
    for(int i=1;i<strlen(s);i++)
    {
        if(s[i]!=s[i-1])
        {
            cnt[i] = cnt[i-1]+1;
            maxn = max(cnt[i],maxn);
        }
        else cnt[i] = 1;
    }
    printf("%d",maxn);
    return 0;
}
