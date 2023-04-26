#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//8.19 1.47 3.83 3.91 12.25 2.26 1.71 4.57 7.10 0.14 0.41 3.77 3.34 7.06 7.26 2.89 0.09 6.85 6.36 9.41 2.58 1.09 1.59 0.21 1.58 0.08
double fz[128] = {};

int cmp(const void* a,const void* b)
{
    char* c = (char*)a; char* d = (char*) b;
    if (fz[*c]!=fz[*d]) return (fz[*c]-fz[*d]>=0)?-1 :1;
    if (abs(*c-*d)<26) return (*c<*d)?-1 :1;
    if (*c>='a') return (*c-'a'+'A'<=*d)?-1: 1;
    return (*d-'a'+'A'<=*c)?1: -1;
}

main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        char s[101] = {};
        for (int j='A';j<='Z';j++) {scanf("%lf",&fz[j]); fz[j-'A'+'a'] = fz[j];}
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    system("pause");
    return 0;
}