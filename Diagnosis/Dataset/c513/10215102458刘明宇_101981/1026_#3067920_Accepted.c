#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int cmp(const void *a,const void *b){
    int * d1 = (int *)a;
    int *d2 = (int *)b;
    return (*d1 - *d2);
}


int main()
{
    int n;
    scanf("%d",&n);
    int list[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&list[i]);
    }
    qsort(list,n,sizeof(list[0]),cmp);
    int sum = 0;
    for(int i = 1;i < n;i+=2){
        sum += list[i] - list[i-1];
    }
    printf("%d",sum);
    return 0;
}
