#include <stdio.h>
#include <string.h>

int main()
{
    char s[101];
    scanf("%s",s);
    int i = 0, j = 0;
    char S[201];
    while(i < strlen(s) - 1)
    {
        if(s[i] == s[i + 1])
        {
            int t = 1;
            while(s[i] == s[i + t]) t++;
            if(s[i] < s[i + t])
            {
                for(int k = i + t; i < k; i++)
                {
                    S[j++] = s[i];
                    S[j++] = s[i];
                }   
            }
            if(s[i] > s[i + t])
                for(int k = i + t; i < k; i++) S[j++] = s[i];
        }
        if(s[i] < s[i + 1])
        {
            S[j++] = s[i];
            S[j++] = s[i++];
        }
        if(s[i] > s[i + 1]) S[j++] = s[i++];
    }
    S[j] = '\0';
    printf("%s",S);
}
