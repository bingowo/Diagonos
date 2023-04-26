#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double f[26];
int cmp(const void *a,const void *b)
{
    char *a1 = (char *)a,*b1=(char *)b;
    int p1,p2;
    if(*a1 >= 'a')
        p1=*a1 - 'a';
    else
        p1=*a1 - 'A';
    if(*b1 >= 'a')
        p2=*b1 - 'a';
    else
        p2=*b1 - 'A';
    if(f[p1] < f[p2])
        return 1;
    else if(f[p1] == f[p2])
    {
        if(p1 == p2)
            return *b1 - *a1;
        else
            return p1-p2;
    }
    else
        return -1;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {

        for(int j=0;j<26;j++)
            scanf("%lf",&f[j]);
        char s[101];
        scanf("%s",s);
        qsort(s,strlen(s),sizeof (s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}
