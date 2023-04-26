#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char alpha;
    double x;
} AAA;

int cmp(const void* p3,const void* p4)
{
    AAA* p1=(AAA* )p3;
    AAA* p2=(AAA* )p4;
    int x1=(p1->alpha)-'a'>0 ? (p1->alpha)-'a':(p1->alpha)-'A' ;
    int x2=(p2->alpha)-'a'>0 ? (p2->alpha)-'a':(p2->alpha)-'A' ;
    if((p1->x)<(p2->x)) return 1;
    else if((p1->x)>(p2->x)) return -1;
    else{
        if((p1->alpha)-(p2->alpha)=='a'-'A') return -1;
        else if((p1->alpha)-(p2->alpha)=='A'-'a') return 1;
        else if(x1>x2) return 1;
        else return -1;
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int ii=0;
        double vv[26];
        for(;ii<26;ii++) scanf("%lf",&vv[ii]);
        char s1[101];
        scanf("%s",s1);
        int n=strlen(s1);
        AAA* p=(AAA* )malloc(n*sizeof(AAA));
        for(int j=0;j<n;j++){
            int ab=(s1[j]-'A')<26 ?  s1[j]-'A':s1[j]-'a';
            (p+j)->alpha=s1[j];
            (p+j)->x=vv[ab];
        }
        qsort(p,n,sizeof(AAA),cmp);
        printf("case #%d:\n",t);
        for(int jj=0;jj<n;jj++) printf("%c",(p+jj)->alpha);
        printf("\n");
        free(p);
    }
    return 0;
}
