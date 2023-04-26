#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// min is for the minimum of dict order
int main()
{
    char s[120] = {0};
    int status[120] = {0};
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len-1; i++) {
        if (s[i+1] > s[i]) status[i] += 1;
    }
    for (int i = 0; i < len; i++) {
        if (status[i]) printf("%c", s[i]);
        printf("%c", s[i]);
    }
    return 0;
}
