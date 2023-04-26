#include <stdio.h>
#include <algorithm.h>
double p[27];

int cmp(const void * a, const void * b)
{
    char ch1, ch2; //待比较字符
    int p1, p2; //p1,p2 为ch1, ch2 在字母表中的序号
    ch1=*((char *)a);
    ch2=*((char *)b);
    if (ch1 >= 'a' && ch1 <= 'z') p1 = ch1 - 'a'; else p1 = ch1 - 'A';
    if (ch2 >= 'a' && ch2 <= 'z') p1 = ch2 - 'a'; else p2 = ch2 - 'A';
    
    if(p[p1] < p[p2])  return -1; // 按字母频率排序
    else if (p[p1] == p[p2])      // 字母使用频率相同
        if (p1 == p2)
            return ch2 - ch1; //相同字母，降序排列，即小写在大写前面
        else return p1 - p2; //不同字母，但使用频率相同，按字母表顺序排列
    else return 1;

}

int main (void)
{
    for (int i =0; i < 26; i++)
        scanf("%lf",&p[i]);
    char str[101];
    scanf("%s", str);
    
    qsort(str, strlen(str),sizeof(str[0]), cmp);
    printf("%s\n", str);
}