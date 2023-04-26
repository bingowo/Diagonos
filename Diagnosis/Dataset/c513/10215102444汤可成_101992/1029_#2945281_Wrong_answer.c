#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* pa, const void*pb)
{
    char* a = (char*)pa;
    char* b = (char*)pb;
    return *a - *b;
}


int main()
{
    int T = 0;
    int i = 0;
    scanf("%d", &T);
    getchar();
    for(i = 0; i<T; i++)
    {
        char word[201] = {0};
        char ch[201] = {0};
        char c = 0;
        int p = 0;
        int q = 0;

        while((c = getchar())!='\n')
        {
            if(c>='A' && c<='Z')
            {
                word[q++] = c;
                p++;
            }
            else
            {
                ch[p++] = c;
            }
        }
        qsort(word,q,1,cmp);

        printf("case #%d:\n",i);
        int t = 0;
        for(int j = 0; j<q; j++)
        {
            if(ch[j] == 0)
                printf("%c", word[t++]);
            else printf("%c", ch[j]);
        }
        printf("\n");
    }
    return 0;
}
