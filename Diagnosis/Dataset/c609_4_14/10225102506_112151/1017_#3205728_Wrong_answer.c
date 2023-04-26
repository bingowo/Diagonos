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
    while(scanf("%d",&num[i])!=EOF)
        i++;
    if(x=='A')
        qsort(num,i-1,sizeof(int),cmp1);
    if(x=='D')
        qsort(num,i-1,sizeof(int),cmp2);
    printf("%d",num[0]);
    for(j=0;j<i-1;j++){
        if(num[j]!=num[j+1])
            printf(" %d",num[j+1]);
    }
    return 0;
}
