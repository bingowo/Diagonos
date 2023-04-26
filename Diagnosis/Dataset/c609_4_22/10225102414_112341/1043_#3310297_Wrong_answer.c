#include <stdio.h>

char *Judge(char *s, int p)
{
    char ch = getchar();
    if (ch == '\n') return "Yes";
    switch (ch){
        case '(':
            if (s[p] != '[' && p != -1){
                scanf("%s", s);getchar();return "No";
            }else{
                s[++p] = ch;
                return Judge(s, p);
            }
            break;
        case '[':
            if (s[p] != '{' && p != -1){
                scanf("%s", s);getchar();return "No";
            }else{
                s[++p] = ch;
                return Judge(s, p);
            }
            break;
        case '{':
            if (s[p] != '(' && p != -1){
                scanf("%s", s);getchar();return "No";
            }else{
                s[++p] = ch;
                return Judge(s, p);
            }
            break;
    }
    return Judge(s, p - 1);
}

int main()
{
    int T;char s[101];
    scanf("%d", &T);getchar();
    while (T--){
        *s = getchar();
        printf("%s\n", Judge(s, 0));
    }
    return 0;
}


