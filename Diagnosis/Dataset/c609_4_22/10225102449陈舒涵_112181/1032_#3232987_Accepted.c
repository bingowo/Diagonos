#include <stdio.h>
#include <string.h>

int main()
{
    int count = 1, max = 0;
    char s[51];
    scanf("%s", s);
    for (int i = 1; i < strlen(s); i ++){
        if (s[i] != s[i - 1]){
            count ++;
        }
        else{
            if (count > max) max = count;
            count = 1;
        }
    }
    if (count > max) max = count;
    printf("%d", max);
    return 0;
}
