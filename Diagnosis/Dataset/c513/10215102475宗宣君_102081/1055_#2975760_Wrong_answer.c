#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
int len;
int begin;
}record;
int cmp(const void*a,const void *b)
{
    if((*(record*)a).len<(*(record*)b).len )return 1;
    else return -1;
}
int main()
{
    char s[10000];int b[123] = {0};
    record a[10000];
    scanf("%s",s);
    int i,j = 0,p;
    for(i = 0;i<strlen(s);i++)
    {
        int c = s[i];
        if(b[c]== 0) {a[j].len++;b[c] = 1;}
        else{j++;a[j].len = 0;a[j].begin = i;
        for(p = 0;p<123;p++)
            b[p] = 0;
        }
    }
    qsort(a,j,sizeof(record),cmp);
    for(j = a[0].begin;j<a[0].begin+a[0].len;j++)
        printf("%c",s[j]);
    return 0;
}
