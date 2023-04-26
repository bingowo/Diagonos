#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* pa, const void*pb)
{
    char* a = (char*)pa;
    char* b = (char*)pb;
    return *a - *b;
}

int is_word(char* s)
{
    int len = strlen(s);
    int flag = 1;
    for(int i = 0; i<len; i++)
    {
        if(s[i]<'A' || s[i]>'z' || (s[i]>'Z' && s[i]<'a'))
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    int T = 0;
    int i = 0;
    scanf("%d", &T);
    getchar();
    for(i = 0; i<T; i++)
    {
        char s[201] = {0};
        char word[201] = {0};
        char ch[201] = {0};
        int w[201] = {0};
        int c[201] = {0};
        char a = 0;
        for(int j = 0; j<100; j++)
        {
            w[j] = 0;
            c[j] = 0;
        }
        int p = 0;
        int q = 0;
        int r = 0;
        do
        {
            scanf("%s", word);
            if(is_word(word))
            {
                int len = strlen(word);
                w[q++] = len;
                for(int j = 0; j<len; j++)
                {
                    s[p++] = word[j];
                }
            }
            else
            {
                int len = strlen(word);
                c[q++] = len;
                for(int j = 0; j<len; j++)
                {
                    ch[r++] = word[j];
                }
            }
        }
        while((a = getchar())!='\n');
        qsort(s,p,1,cmp);
        printf("case #%d:\n",i);
        int e = 0;
        int f = 0;
        for(int j = 0; j<q; j++)
        {
            if(w[j] != 0)
            {
                int len = w[j];
                for(int m = 0; m<len; m++)
                {
                    printf("%c",s[m+e]);
                }
                e += len;
                printf(" ");
            }
            else
            {
                int len = c[j];
                for(int m = 0; m<len; m++)
                {
                    printf("%c", ch[m+f]);
                }
                f += len;
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
