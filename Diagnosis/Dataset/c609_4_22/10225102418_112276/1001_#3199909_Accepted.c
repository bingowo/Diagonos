#include <stdlib.h>
#include <stdio.h>

int main()
{
    char table[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    // stack<char> s;
    char s[100] = {'\0'};
    int T, N, R;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &R);
        int flag = 0;
        if (N < 0)
        {
            N *= -1;
            flag = 1;
        }
        int i = 0;
        while (N)
        {
            int tmp = N % R;
            s[i] = table[tmp];
            ++i;
            // s.push(table[tmp]);
            N /= R;
        }
        if (flag)
            printf("-");
        while (i != -1 /*!s.empty()*/)
        {
            printf("%c", s[i - 1]);
            // cout << s.top();
            // s.pop();
            --i;
        }
        printf("\n");
    }
    return 0;
}