#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
double p[26];
int cmp(const void *a,const void *b)
{
    char x=*(char *)a;
    char y=*(char *)b;
    int p1,p2;
    if(x>='a')
        p1=x-'a';
    else
        p1=x-'A';
    if(y>='a')
        p2=y-'a';
    else
        p2=y-'A';
    if(p[p1]<p[p2]) return 1;
    else if (p[p1] == p[p2])
    {
        if (p1 == p2) return y-x;
        else
        {
            return p1-p2;
        }
    }
    else
    {
        return -1;
    }

}
int main()
{
    int t;
    char s[150];
    scanf("%d",&t);
    for(int m=0;m<t;m++)
    {
        for(int k=0;k<26;k++)
            scanf("%lf",&p[k]);
        scanf("%s",s);
        int len= strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        printf("case #%d:\n",m);
        printf("%s\n",s);
    }
    return 0;
}