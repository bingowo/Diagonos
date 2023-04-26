#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct{
    char c;
    double num;
}node;

double find(char c,double *d)
{
    c = toupper(c);
    return d[c-'A'];
}

int cmp(const void *a,const void *b)
{
    node *pa = (node*)a;
    node *pb = (node*)b;
    if(pa->num != pb->num)
    {
        if(pa->num > pb->num)
            return -1;
        else
            return 1;
    }
    else
    {
        if(abs((pa->c)-(pb->c)) == 'a'-'A')
            return pb->c - pa->c;
        else
            return pa->c - pb->c;
    }
}

int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        node *ch = (node*) malloc(100*sizeof*ch);
        printf("case #%d:\n",i);
        double d[26] = {0};
        for(int j = 0;j < 26;j++)
        {
            scanf("%lf",&d[j]);
        }
        int t;t = getchar();
        int cnt = 0;
        char res;
        while(1)
        {
            res = getchar();
            if(res == '\n')
                break;
            ch[cnt].c = res;
            ch[cnt++].num = find(res,d);
        }
        qsort(ch,cnt,sizeof(ch[0]),cmp);
        for(int j = 0;j < cnt;j++)
        {
            putchar(ch[j].c);
        }
        putchar('\n');
        free(ch);
    }

    return 0;
}