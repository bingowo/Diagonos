#include <stdio.h>
#include <math.h>
#include <string.h>

 int max(int a,int b)
{
     if(a>b) return a;
     else return b;
 }

int main() {
    char s[100000];
    int cnt[100000];
    char ch;
    while (ch=getchar()!=EOF) {
        scanf("%s",s);
    }
    cnt[0]=1;
    int maxn=1;
    for (int i=1; i<strlen(s); i++) {
        if(s[i] != s[i-1]){
            cnt[i] = cnt[i-1]+1;
            maxn = max(cnt[i],maxn);
        }
        else cnt[i]=0;
    }
    printf("%d",maxn);
    return 0;
}