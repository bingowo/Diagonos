#include <stdio.h>
#include <string.h>

int main() {
    char s[51];
    scanf("%s",s);
    int len= strlen(s);
    int num=1,cnt=1;
    for(int i=1;i<len;i++)
    {
        if(s[i-1] != s[i])
            cnt++;
        else
        {
            num=(num>cnt)?num:cnt;
            cnt=1;
        }
    }
    printf("%d\n",num);
    return 0;
}
