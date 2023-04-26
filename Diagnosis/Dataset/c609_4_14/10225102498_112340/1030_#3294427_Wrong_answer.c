#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double pro[26];

int cmp(const void* m, const void* n)
{
    char a = *(char*)m, b = *(char*)n;
    int an, bn;
    if(a>='a')
        an = a - 'a';
    if(a<='Z')
        an = a - 'A';
    if(b>='a')
        bn = b - 'a';
    if(b<='Z')
        bn = b - 'A';

    if(an != bn)
    {
        if(pro[an] >= pro[bn])
            return -1;
        return 1;
    }

    if(a > b)
        return -1;
    return 1;

}

int main()
{
    int T, i, j, len;
    char str[101] = {0};
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        for(j=0; j<26; j++)
            scanf("%lf", &pro[j]);
        scanf("%s", str);
        len = strlen(str);

        qsort(str,len,sizeof(char),cmp);
        printf("case #%d:\n%s\n", i, str);
    }

    return 0;
}
