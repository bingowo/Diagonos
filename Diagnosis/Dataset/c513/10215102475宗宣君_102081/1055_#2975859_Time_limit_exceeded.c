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
    else if((*(record*)a).len==(*(record*)b).len&&((*(record*)b).begin<(*(record*)a).begin)) return 1;
    else return -1;
}
int main()
{
    char s[1000000];
    record a[100000];
    scanf("%s",s);
    int i,j = 0,p;
    for(p = 0;p<strlen(s);p++)
    {
        int b[123] = {0};
        a[j].begin = p;
        a[j].len = 0;
        for(i = p;i<strlen(s);i++)
        {
            int c = s[i];
            if(b[c]== 0) {a[j].len++;b[c] = 1;}
            else break;
        }
        j++;
    }

    qsort(a,j,sizeof(record),cmp);
    for(j = a[0].begin;j<a[0].begin+a[0].len;j++)
        printf("%c",s[j]);
    return 0;
}
