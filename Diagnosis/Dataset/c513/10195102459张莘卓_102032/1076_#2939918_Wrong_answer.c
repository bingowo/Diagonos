#include <stdio.h>
#include <string.h>

char* find_end(char* s) {
    if(*s == 0) return s;
    int cnt = 0, i;
    char c = s[0]=='('? s[0]+1 : s[0]+2;
    for(i=0; s[i]; ++i) {
        if(s[i] == s[0]) ++cnt;
        else if(s[i] == c) --cnt;
        if(cnt == 0) return s + i;
    }
    return NULL;
}

int iseleg(char *s, char *end, int flag){
    if(s > end) return 1;
    char *mid = find_end(s);
    if(mid == NULL) return 0;
    int nf = s[0]=='{' ? 1 : (s[0]=='[' ? 2 : 3);
    if(flag && nf != flag%3+1) return 0;
    
    if(mid == end) return iseleg(s+1,end-1, nf);
    return iseleg(s+1, mid-1, nf) && iseleg(mid+1, end-1, flag);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; ++i) {
        char s[101];
        scanf("%s",s);
        int t = iseleg(s,s+strlen(s)-1,0);
        printf("%s\n",t ? "Yes" : "No");
    }
    return 0;
}