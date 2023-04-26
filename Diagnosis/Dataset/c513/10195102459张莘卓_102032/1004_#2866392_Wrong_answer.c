#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int toInt(char *s) {
    int ans = 0;
    for(int i=0; s[i] && s[i]!='.'; ++i)
        ans = ans*10 + s[i] - '0';
    return ans;
}

double toDouble(char *s, int len) {
    double ans = 0.0;
    for(int i=len-1; s[i]!='.'; --i){
        ans += s[i] - '0';
        ans /= 10.0;
    }
    ans += (double) toInt(s);
    return ans;
}

int main()
{
    char s[1000];
    while(scanf("%s",s) != EOF) {
        
    }
}
