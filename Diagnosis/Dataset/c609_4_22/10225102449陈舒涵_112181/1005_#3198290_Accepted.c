#include <stdio.h>
#include <string.h>

int main()
{
    int T, ans;
    scanf("%d", &T);
    for (int t = 0; t < T; t ++){
        ans = 0;
        char s[100];
        scanf("%s", &s);
        for (int i =0; i < strlen(s); i ++){
            if (s[i] == '-'){
                ans = ans * 3 - 1;
            }
            else if (s[i] == '0'){
                ans = ans * 3;
            }
            else{
                ans = ans * 3 + 1;
            }
        }
        printf("case #%d:\n%d\n", t, ans);
    }
    return 0;
}
