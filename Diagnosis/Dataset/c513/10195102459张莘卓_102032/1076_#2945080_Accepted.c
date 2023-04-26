#include <stdio.h>
#include <string.h>

char* find(char* s) {
    char target = s[0]=='{'?'}':(s[0]=='['?']':')');
    int cnt = 0;
    for(int i=0; s[i]; ++i) {
        if(s[i] == s[0]) ++cnt;
        else if(s[i] == target) --cnt;
        if(cnt == 0) return s + i;
    }
    return NULL;
}
char a[4] = {' ','[','(','{'};
int iselg(char* s, char* end, int flag) {
    if(end-s+1 == 0) return 1;
    if((end-s+1) % 2) return 0;
    char* mid = find(s);
    if(mid == NULL) return 0;
    if(flag && *s!=a[flag]) return 0;
    int next = *s=='{'? 1 : (*s=='['? 2:3);
    return iselg(s+1, mid-1, next) && iselg(mid+1, end, flag);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; ++i) {
        char s[101];
        scanf("%s",s);
        printf("%s\n",iselg(s, s+strlen(s)-1, 0)?"Yes":"No");
    }
    return 0;
}
