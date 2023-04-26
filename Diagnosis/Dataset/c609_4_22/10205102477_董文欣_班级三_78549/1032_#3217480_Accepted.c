#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int n = strlen(s);
    int max = 1;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i-1] == s[i]) {cnt = 1; continue;}
        else {cnt++;}
        max = max > cnt ? max : cnt;
    }
    printf("%d\n",max);
    return 0;
}
