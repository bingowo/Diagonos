#include <stdio.h>
#include<stdlib.h>
#include<string.h>
const int N=1e5+7;
int sum1[N],sum2[N],len1,len2;
char s1[N],s[N],s2[N];
int main()
{
    scanf("%s",s+1);
    int len = strlen(s+1);
    for(int i = 1;i <= len ;i ++) {
        if(s[i] != s[i-1]) 
            s1[++len1] = s[i];
        sum1[len1] ++;
    }
    scanf("%s",s+1);
    len = strlen(s+1);
    for(int i = 1;i <= len ;i ++) {
        if(s[i] != s[i-1]) 
            s2[++len2] = s[i];
        sum2[len2] ++;
    }
    for(int i = 1;i <= len2;i ++) 
        if(s1[i] != s2[i]) {
            puts("-1");
            return 0;
        }
    int ans = 0;
    for(int i = 1;i <= len1;i ++) 
        ans += abs(sum1[i]-sum2[i]);
        return 0;
}
