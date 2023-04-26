#include <stdio.h>
#include <stdlib.h>
char flag;

int cmp(const void *a,const void *b){
    int *p1=(int*)a;
    int *p2=(int*)b;
    if (flag == 'A'){
        return (*p1)-(*p2);
    }else{
        return (*p2)-(*p1);
    }
}


int main()
{
    int a[100];
    int i=0;
    scanf("%c",&flag);
    while( scanf("%d",&a[i])!=EOF ){
        i++;
    }
    qsort(a,i,sizeof(int),cmp);
    int j=0;
    printf("%d ",a[j]);
    for(j=1;j<i;j++){
        if(a[j]!=a[j-1]){
            printf("%d ",a[j]);
        }
    }
    return 0;
}
