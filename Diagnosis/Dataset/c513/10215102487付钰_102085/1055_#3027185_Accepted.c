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
        if(j - i + 1 > l) {//最长子字符更新了
            a = i;//p1
            b = j;//p2
            l = j - i + 1;//最长长度
        }
        //line 是指针 所以line[j]就是按顺序来的 aabcbbb line[0]=1 line[1]=2
        index[line[j]] = j + 1;//该字符最新一次出现位置+1
    }
    line[b + 1] = 0;//将后续的字符都删除
    puts(line + a);//从a开始输出
    return 0;
}
