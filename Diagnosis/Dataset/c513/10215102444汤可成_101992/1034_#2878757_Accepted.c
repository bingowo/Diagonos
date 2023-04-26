#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double arr[26] = {0};

int cmp(const void*a, const void* b)
{
    char* pa = (char*)a;
    char* pb = (char*)b;
    double aa = 0;
    double bb = 0;
    if (*pa >= 'A' && *pa <= 'Z')
    {
        aa = arr[*pa -'A'];
    }
    else
    {
        aa = arr[*pa - 'a'];
    }
    if (*pb >= 'A' && *pb <= 'Z')
    {
        bb = arr[*pb -'A'];
    }
    else
    {
        bb = arr[*pb - 'a'];
    }
    if (aa > bb) return -1;
    else if (aa < bb) return 1;
    else
    {
        if(*pa - *pb == 'a' - 'A' ||*pa - *pb == 'A' - 'a' ) return *pb - *pa;
        else
        {
            return *pa - *pb;
        }
    }
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    int i = 0;
    for (i = 0; i<T; i++)
    {
        int j = 0;
        for (j = 0; j<26; j++)
        {
            scanf("%lf", &arr[j]);
        }
        char s[100] = {0};
        scanf("%s",s);
        int len = strlen(s);
        qsort(s, len, sizeof(char), cmp);
        printf("case #%d:\n", i);
        printf("%s\n",s);
    }
    return 0;
}
