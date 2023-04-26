#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    char c;
    double d;//d为频率
}C;

int cmp(const void *_a,const void *_b)
{
    int p1,p2;
    C a,b;
    a = *((C*)_a);
    b = *((C*)_b);
    if(a.c >= 'a' && a.c <= 'z') p1 = a.c-'a';
    else p1 =a.c-'A';
    if(b.c >= 'a' && b.c <= 'z') p2 = b.c-'a';
    else p2 = b.c-'A';
    if(b.d > a.d) return 1;
    else if(b.d == a.d)
    {
        if(p1 == p2) return b.c-a.c;
        else  return p1-p2;
    }
    else return -1;
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++)
    {
        double A[26];//表示26个英文字母使用频率
        for(int j = 0; j < 26; j++)
        {
             scanf("%lf ",&A[j]);
        }
        char c;
        C s[101];
        int l = 0;
        getchar();
        while((c = getchar())!='\n')
        {
            s[l].c = c;
            if(c <= 'z' && c >= 'a')
                s[l++].d = A[c-97];
            else
                s[l++].d = A[c-65];
        }
        qsort(s,l,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int j = 0; j < l; j++)
            printf("%c",s[j].c);
        printf("\n");
    }
    return 0;
}
