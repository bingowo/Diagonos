#include <stdio.h>
#include <string.h>

int main()
{
    char s[101];
    scanf("%s",s);
    int i = 0, j = 0;
    char S[201];
    while(i < strlen(s))
    {
        int t = 1;
        while(s[i] == s[i + t]) t++;
        int k = i + t;
        while(i < k)
        {
            if(s[i] < s[k]) S[j++] = s[i];
            S[j++] = s[i++];
        }
    }
    S[j] = '\0';
    printf("%s",S);
}
