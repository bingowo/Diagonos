#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}

int cmp2(const void *a,const void *b){
    return *(int *)b-*(int *)a;
}

int main()
{
    char x;
    int i=0,j;
    int num[1000];
    scanf("%c",&x);
    while(scanf("%d",&num[i++])!=EOF);
    if(x=='A')
        qsort(num,i-1,sizeof(int),cmp1);
    if(x=='D')
        qsort(num,i-1,sizeof(int),cmp2);
    for(j=0;j<i-1;j++){
        if(num[j]==num[j+1] && j+1<i-2)
            continue;
        if(j==i-2)
            printf("%d",num[j]);
        else
            printf("%d ",num[j]);
    }
    return 0;
}
