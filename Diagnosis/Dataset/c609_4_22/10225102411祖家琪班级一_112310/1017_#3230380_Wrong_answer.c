#include <stdio.h>
#include <stdlib.h>

int main()
{
    char flag;
    int n[100],cnt = 0;
    scanf("%c",&flag);
    int cmpA(const void *a,const void *b);
    int cmpD(const void *a,const void *b);
    do{
        scanf("%d",&n[cnt++]);
    }while(getchar() != EOF);
    if('A' == flag){
        qsort(n,cnt,4,cmpA);
    }
    else{
        qsort(n,cnt,4,cmpD);
    }
    return 0;
}
int cmpA(const void *a,const void *b)
{
    int *pa = (const int*) a;
    int *pb = (const int*) b;
    return *pa - *pb;
}
int cmpD(const void *a,const void *b)
{
    int *pa = (const void*) a;
    int *pb = (const void*) b;
    return *pb - *pa;
}
