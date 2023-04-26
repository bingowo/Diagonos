#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void *a,const void *b)
{
    int *p1,*p2;
    p1 = (int *)a;
    p2 = (int *)b;
    return (*p1) - (*p2);

}

int main()
{
    int n;
    scanf("%d",&n);
    int list[100000];
    for(int i = 0;i<n;i++){
        scanf("%d",&list[i]);
    }
    qsort(list,n,sizeof(list[0]),cmp);
    int sum = 0;
    for(int i =0;i<n-1;i+=2){
        sum += (list[i+1] - list[i]);
    }
    printf("%d\n",sum);

}