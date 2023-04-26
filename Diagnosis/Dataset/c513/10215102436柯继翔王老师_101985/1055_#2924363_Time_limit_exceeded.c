#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    char s[1000000];

int main()
{
    scanf("%s",s);
    int m[128],start = 0,len = 0;
    for(int i = 0;i < 128;i++) m[i]=-1;
    int t = 0;
    for(int i = 0;i < strlen(s);i++){
        if(m[s[i]] >= t){
            t = m[s[i]] + 1;
            m[s[i]] = i;
        }else{
            m[s[i]] = i;
            if(len < i - t + 1){
                start = t;
                len = i - t + 1;
            }
        }
    }
    for(int i = 0;i < len;i++)
        printf("%c",s[start + i]);
    return 0;
}
