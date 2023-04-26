#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct SSS
{
    int num;
    char str[35];
}sss;
int cmp(const void*_a,const void*_b)
{
    sss* a=(sss*)_a;
    sss* b=(sss*)_b;
    if(a->num != b->num) return a->num - b->num;
    else return strcmp(a->str,b->str);
}
int main()
{
    char s[35];
    sss a[101];
    int i=0;
    while(scanf("%s",s)!=EOF)
    {
        int flag=0;
        strcpy(a[i].str,s);
        int num=0;
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]>='0' && s[j]<='9')
            {
                num=num*10+s[j]-'0';
                flag=1;
            }
        }
        if(flag==1) a[i].num=num;
        else a[i].num=-1;
        i++;
    }
    qsort(a,i,sizeof(sss),cmp);
    for(int j=0;j<i;j++)
    {
        printf("%s ",a[j].str);
    }
    return 0;
}
