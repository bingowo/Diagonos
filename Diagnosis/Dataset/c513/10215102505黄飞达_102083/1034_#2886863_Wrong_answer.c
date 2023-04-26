#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double fz[128] = {0};

int cmp(const void* a,const void* b)
{
    char* c = (char*)a; char* d = (char*) b;
    if (fz[*c]!=fz[*d]) return (fz[*c]-fz[*d]>=0)?-1 :1;
    if (abs(*c-*d)<26) return *c-*d;
    return *c>='a'? -1:1;
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
        qsort(s,strlen(s)+1,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}
