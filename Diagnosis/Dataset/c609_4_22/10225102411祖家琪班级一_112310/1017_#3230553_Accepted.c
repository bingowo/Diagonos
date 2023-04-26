#include <stdio.h>
#include <stdlib.h>

int main()
{
    char flag;
    int n[100] = {0},cnt = 0,temp;
    scanf("%c",&flag);
    int cmpA(const void *a,const void *b);
    int cmpD(const void *a,const void *b);
    do{
        int isrep = 0;
        scanf("%d",&temp);
        for(int i = 0;i<cnt;i++){
            if(temp == n[i]){
                isrep = 1;
                break;
            }
        }
        if(isrep) continue;
        n[cnt++] = temp;
    }while(getchar() != '\n');
    if('A' == flag){
        qsort(n,cnt,4,cmpA);
    }
    else{
        qsort(n,cnt,4,cmpD);
    }
    for(int i = 0;i < cnt;i++){
        printf("%d%c",n[i],(cnt - 1 == i)?'\n':' ');
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
