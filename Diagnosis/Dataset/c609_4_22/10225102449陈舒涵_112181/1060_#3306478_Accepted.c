#include <stdio.h>
#include <string.h>

int main()
{
    char s[101];
    scanf("%s", s);
    int n = strlen(s);
    char ans[300];
    int i = 0, j = 0;  //i记录字符串s的下标，j记录字符串ans的下标
    while (i < n){
        ans[j++] = s[i];
        int k = i + 1;
        while (s[k] == s[i] && k < n){
            k ++;
        }
        if (k < n && s[k] > s[i]){
            ans[j++] = s[i];
        }
        i ++;
    }
    ans[j] = '\0';
    printf("%s", ans);
    return 0;
}