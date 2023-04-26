#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    char c;
    double alp;
}C;

int cmp(const void *_a,const void *_b)
{
    C a,b;
    a = *((C*)_a);
    b = *((C*)_b);
    if(abs(a.alp - b.alp) > 0.001) return b.alp - a.alp;
    if(abs(a.c-b.c) == 32) return b.c - a.c;
    return a.c - b.c;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++)
    {
        double alp[26];
        for(int j = 0; j < 26; j++)
            scanf("%lf",&alp[j]);
        char ch;
        C str[105];
        int len = 0;
        getchar();
        while((ch=getchar())!='\n')
        {
            str[len].c = ch;
            if(ch <= 'z' && ch >= 'a')
                str[len++].alp = alp[ch-97];
            else
                str[len++].alp = alp[ch-65];
        }
        qsort(str,len,sizeof(str[0]),cmp);
        printf("case #%d:\n",i);
        for(int j = 0; j < len; j++)
            printf("%c",str[j].c);
        printf("\n");
    }
    return 0;
}
