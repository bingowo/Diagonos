#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int order_num[26] = {0};

int cmp(const void *a,const void *b)
{
    char *s1 = (char *)a;
    char *s2 = (char *)b;
    while (*s1 && *s2)
    {
        char c1,c2;
        c1 = *s1 >= 'a' ? *s1 - 32 : *s1;
        c2 = *s2 >= 'a' ? *s2 - 32 : *s2;
        if (order_num[c1 - 'A'] != order_num[c2 - 'A'])
            return order_num[c1 - 'A'] - order_num[c2 - 'A'];
        else
            {s1++;s2++;}
    }
    if (*s1 == 0) return -1;
    else return 1;
}

int main()
{
    char order[26]; //字母顺序

    while (scanf("%s",order) != EOF) {
        getchar();

        for (int t = 0; t < 26; t++) {
            order_num[order[t] - 'A'] = t;
        }

        char str[2000] = {'0'};
        gets(str);

        char s[101][21] = {'0'}; //字符串组
        int i = 0, j = 0;
        while (str[i]) {
            int k = 0;
            while (str[i] && str[i] != ' ') {
                s[j][k++] = str[i++];
            }
            s[j][k] = '\0';
            j++;
            if (!str[i]) break;
            else i++;
        }

        qsort(s, j, sizeof(s[0]), cmp);

        for (int i = 0; i < j; i++) {
            printf("%s%c",s[i],i == j - 1 ? '\n' : ' ');
        }

    }

    return 0;
}
