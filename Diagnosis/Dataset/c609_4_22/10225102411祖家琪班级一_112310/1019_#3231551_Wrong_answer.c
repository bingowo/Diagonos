#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *n = (int *)malloc(4e6),cnt = 0;
    int cmp(const void*,const void*);
    do{
        scanf("%d",(n+cnt));
        cnt++;
    }while(getchar() != '\n');
    qsort(n,cnt,4,cmp);
    for(int i = 0;i<cnt;i++){
        printf("%d%c",*n+i,(i == cnt - 1)?'\n':' ');
    }
    return 0;
}
int cmp(const void *a,const void *b)
{
    const int *pa = (const int *)a;
    const int *pb = (const int *)b;
    int vala = *pa;
    int valb = *pb;
    int lena = 0,lenb = 0;
    do{
        vala /= 10;
        lena++;
    }while(vala);
    do{
        valb /= 10;
        lenb++;
    }while(valb);
    if(lena == lenb){
        return *pa - *pb;
    }
    else return lenb - lena;
}
