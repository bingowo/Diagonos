#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int num;
    char ch;
}string;

int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        printf("case #%d:\n", i);
        char s[501] = {0};
        scanf("%s", s);
        int len = 0;
        len = strlen(s);
        int j = 0;
        string ret[501] = {0};
        int num = 1;
        int r = 0;
        for(j = 0; j<len; j++)
        {
            if(s[j] != s[j+1] || num == 255)
            {
                ret[r].num = num;
                ret[r++].ch = s[j];
                num = 1;
            }
            else
            {
                num++;
            }
        }
        j = 0;
        while((ret[j].num)!=0)
        {
            printf("%d%c", ret[j].num, ret[j].ch);
            j++;
        }
        printf("\n");
    }
    return 0;
}
