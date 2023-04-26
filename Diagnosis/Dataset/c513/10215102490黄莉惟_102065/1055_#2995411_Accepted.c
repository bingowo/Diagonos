#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a, b) (a > b? a: b)

typedef long long ll;
int main()
{
    char *line = malloc(2000000 * sizeof(char));
    gets(line);
    int n = strlen(line), l = 0;
    int index[128] = {0};
    int a = 0, b = 0;
    for (int j = 0, i = 0; j < n; j++) {
        i = max(index[line[j]], i);
        if(j - i + 1 > l) {
            a = i;
            b = j;
            l = j - i + 1;
        }
        index[line[j]] = j + 1;
    }
    line[b + 1] = '\0';
    puts(line + a);//从第a位开始输出
    return 0;
}