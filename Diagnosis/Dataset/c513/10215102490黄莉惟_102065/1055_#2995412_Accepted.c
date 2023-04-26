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
    int i=0;
    for (int j = 0; j < n; j++) {
        i = max(index[line[j]], i);//如果line[j]表示的字符出现过，i=j+1
        if(j - i + 1 > l) {
            a = i;//a记录子串起点
            b = j;//b记录子串终点
            l = j - i + 1;//l为子串长度
        }
        index[line[j]] = j + 1;//line[j]>=0,line[j]<=127,
    }
    line[b + 1] = '\0';
    puts(line + a);//从第a位开始输出
    return 0;
}