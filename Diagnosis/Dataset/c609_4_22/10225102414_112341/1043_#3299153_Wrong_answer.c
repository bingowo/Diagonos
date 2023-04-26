#include <stdio.h>

char *Judge(char *s)
{
    int yourfriends = 1, len = strlen(s);
    for (int i = 1;i < len;i++){
        if (s[0] == s[i]) yourfriends++;
        else if(s[0] == s[i] + 1 || s[0] == s[i] + 2){
            if (yourfriends == 1) break;
            else yourfriends--;
        }
    }
}

int main()
{
    int T, i;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        char s[100];
        scanf("%s", s);printf("%s\n", Judge(s));
    }
    return 0;
}