#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[256] = {0};

typedef struct
{
    char str1[25]
}strs;

int cmp(const void *a, const void *b)
{
    int len1 = strlen(a);
    int len2 = strlen(b);

    char *A = (char *)a;
    char *B = (char *)b;

    for(int i = 0; i < len1 && i < len2; i++)
    {
        if(A[i] != B[i])  return table[A[i]] < table[B[i]];
    }

    return len1 < len2;
}

int main()
{
    char ch;

    while(scanf("%c", &ch) != EOF)
    {
        for(int i = 0; i < 52; i += 2)//第一行字母
        {
            table[ch] = i;
            table[ch + 32] = i + 1;
            scanf("%c", &ch);
        }

        strs str2[105];
        int number = 0;
        int j = 0;

        ch = getchar();//需要排序的字符串
        while(scanf("%c", &ch) != EOF)
        {
            if(ch == '\n')  break;

            if(ch == ' ')
            {
                str2[number].str1[j] = '\0';
                number++;
                j = 0;
            }

            else  str2[number].str1[j++] = ch;
        }

        qsort(str2, number + 1, sizeof(strs), cmp);

        for (int i = 0; i <= number; i++) {
            printf("%s%c", str2[i].str1, i == number ? '\n' : ' ');
        }
    }

    return 0;
}