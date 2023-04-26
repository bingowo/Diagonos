#include <stdio.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        char s[100];
        scanf("%s", s);
        int Lth = strlen(s);
        int ans = 0;
        for(int j = 0 ; j < Lth; j++)
        {
            if(s[j] == '-')
            {
                s[j] = -1;
                ans = ans * 3 - 1;
            }
            else if(s[j] == '1') ans = ans * 3 + 1;
            else if(s[j] == '0') ans = ans * 3 + 0;
        }
        printf("case #%d:\n%d\n", i, ans);
    }
    return 0;
}
