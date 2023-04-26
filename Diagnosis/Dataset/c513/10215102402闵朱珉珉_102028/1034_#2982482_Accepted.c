#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double q[27];
int cmp(const void *a,const void *b)
{
    char *a1=(char *)a,*b1=(char *)b;
    char a2=(*a1>'Z')? *a1-'a'+'A':*a1;
    char b2=(*b1>'Z')? *b1-'a'+'A':*b1;
    if ((q[a2-'A']-q[b2-'A'])>0) return -1;
    else if ((q[a2-'A']-q[b2-'A'])<0) return 1;
    else if (abs(*a1-*b1)==32) return *b1-*a1;
    else if (*a1-*b1>0) return 1;
    else return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        for (int j=0;j<26;j++)
        {
            scanf("%lf",&q[j]);
        }
        char s[101]={"0"};
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}
