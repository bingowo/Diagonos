#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct
{
    char c[32];
    int num;
} STRING;

int cmp (STRING *a, STRING *b)
{
    if (a->num != b->num)
    {
        if (a->num > b->num) return 1;
        else return -1;
    }
    else return strcmp(a->c,b->c);

}

void Sort(STRING *ps, int n)
{
    qsort(ps,n,sizeof(STRING),cmp);
}

int main()
{
    STRING *a = (STRING*)malloc(sizeof(STRING) * 111);
    int ai = 0;
    while ((scanf("%s",a[ai].c)) != EOF)
    {
        int ci = 0 , dig = 0, f = -1;
        while (!isdigit(a[ai].c[ci]) && ci != strlen(a[ai].c)) ci++;
        //printf("ci=%d,str=%d ",ci,strlen(a[ai].c));
        while (ci != strlen(a[ai].c) && isdigit(a[ai].c[ci]))
        {
            f = 1;
            dig = dig * 10 + a[ai].c[ci] - '0';
            ci++;
        }
        //int t = 0;
        if (f == 1) a[ai].num = dig;
        else a[ai].num = -1;
        //printf("c=%s,num=%d,f=%d\n",a[ai].c,a[ai].num,f);
        ai++;
    }
    Sort(a,ai);
    for (int i = 0; i < ai; i++)
    {
        printf("%s ",a[i].c);

    }
}