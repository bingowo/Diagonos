#include <stdio.h>
#include <stdlib.h>

int s[26] = {0};
int cmp(const void* a, const void* b)
{
    char* pa = (char*)a;
    char* pb = (char*)b;
    char p, q;
    int i = 0;
    for(i = 0; i<21; i++)
    {
        p = (*(pa+i)) >= 'a'? (*(pa+i)-32):(*(pa+i));
        q = (*(pb+i)) >= 'a'? (*(pb+i)-32):(*(pb+i));
        if(p == 0 && q != 0) return -1;
        if(p != 0 && q == 0) return 1;
        if(s[p-'A'] != s[q - 'A']) return s[p-'A']-s[q-'A'];
    }
}

int main()
{
    char alpha[27] = {0};
    while(scanf("%s", alpha) != EOF)
    {
        int num = 0;
        char word[100][21] = {0};
        int i = 0;
        for (i = 0; i<26; i++)
        {
            s[alpha[i]-'A'] = i;
        }
        getchar();
        char c = 0;
        i=0;
        while((c = getchar()) != '\n')
        {
            if(c != ' ')
            {
                word[num][i++] = c;
            }
            else
            {
                i = 0;
                num++;
            }
        }
        num++;
        qsort(word, num, sizeof(word[0]), cmp);
        for(i = 0; i<num; i++)
        {
            printf("%s ", word[i]);
        }
        printf("\n");
    }
    return 0;
}
