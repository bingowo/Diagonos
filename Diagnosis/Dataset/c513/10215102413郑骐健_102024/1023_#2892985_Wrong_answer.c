#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct num
{
    char s[40];
    int num;
}Num;

int cmp(const void* p1, const void* p2)
{
    Num* p_1 = (Num*)p1;
    Num* p_2 = (Num*)p2;
    if (p_1->num > p_2->num) return 1;
    else if (p_1->num == p_2->num)
    {
        return strcmp(p_1->s, p_2->s);
    }
    else return 0;
}
int main()
{
    char c;
    int a = 0;
    Num p[105];
   do
    {
       scanf("%s%c", p[a].s,&c);
        p[a].num = -1;
        for (int z = 0;z < strlen(p[a].s);z++)
        {
            if (p[a].s[z] >= '0' && p[a].s[z] < '9' + 1)
            {
                if (p[a].num == -1)p[a].num += 1;
                p[a].num *=10;
                p[a].num += p[a].s[z] - '0';
            }
        }
        a++;
   } while (c == ' ');
    qsort(p, a, sizeof(Num), cmp);
    for (int i = 0;i < a;i++)
    {
        printf("%s ", p[a].s);
    }
    return 0;

}
