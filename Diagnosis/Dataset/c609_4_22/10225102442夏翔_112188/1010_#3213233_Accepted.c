#include <stdio.h>
#include <stdlib.h>
const char s[]="0123456789ABCDEFGHIJK";
int main()
{
    int N, R, count=0;
    char *ans;
    ans = (char*)malloc(sizeof(char)*50000);
    scanf("%d %d", &N, &R);
    while(N!=0){
        if(N%R>=0){
            ans[count++] = s[N%R];
            N /= R;
        }else{
            ans[count++] = s[N%R-R];
            N = N/R+1;
        }
    }
    if(count!=0)
        for(int i=count-1; i>=0; i--) printf("%c", ans[i]);
    else printf("%d", 0);
    free(ans);
    return 0;
}
