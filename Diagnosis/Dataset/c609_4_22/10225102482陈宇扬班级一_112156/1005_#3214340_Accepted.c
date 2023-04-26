#include <stdio.h>
#include <string.h>
#include <math.h>
#define LL long long int
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
            if(s[j] == '-') ans = ans - pow(3, 1 * (Lth-1-j));
            else if(s[j] == '1') ans = ans + pow(3, Lth-1-j);
            else if(s[j] == '0') ans += 0;
        }
        printf("case #%d:\n%d\n", i, ans);
    }
    return 0;
}
