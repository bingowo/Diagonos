#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[81];
typedef struct
{
    char c;
    int pos;
}NODE;
int compar(const void* p1, const void* p2)
{
    NODE* a, * b;
    a = (NODE*)p1;
    b = (NODE*)p2;
    if (a->pos > b->pos) return -1;
    else if (a->pos < b->pos) return 1;
    else
    {
        if (strchr(s, a->c) < strchr(s, b->c)) return -1;
        else return 1;
    }
}
int main()
{
    int i,j, k,len,numofspace,pos[100];

    NODE c[81];
    while (scanf("%s", s))
    {
        len = strlen(s);
        memset(pos, 0, sizeof(pos));    //一开始大家的行数都是0,,pos[j]是第j个字符对应的行数
       
        for (i = 1;i < len;i++)       //位置坐标pos大的在上面
        {
            if (s[i] > s[i - 1])
            {
                pos[i] = pos[i - 1] + 1;
            }
            else if (s[i] < s[i - 1])
            {
                pos[i] = pos[i - 1] - 1;
            }
            else
            {
                pos[i] = pos[i - 1];
            }
        }
        for (i = 0;i < len;i++)
        {
            c[i].c = s[i];
            c[i].pos = pos[i];
        }
        qsort(c, len, sizeof(NODE), compar);
        i = 0;
        while (i < len)
        {
            for (j = i;j < len;j++)
            {
                if (c[j].pos != c[i].pos)
                    break;
            }
            j--;                 //同一行的：从i到j
            for (k = 0;k <= (strchr(s, c[j].c) - s);k++)
            {
                if (k == strchr(s, c[i].c) - s)
                {
                    //printf("%d", strchr(s, c[i].c) - s);
                    printf("%c", c[i].c);
                    i++;
                }  
                else
                    printf(" ");
            }
            printf("\n");
            i = j + 1;
        }
    }
    return 0;
}
