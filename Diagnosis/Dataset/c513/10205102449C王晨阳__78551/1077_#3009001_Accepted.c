#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int array[1001];
int position[1001];

int cmp(const void *a, const void *b){
    int a1=*(int *)a,b1=*(int *)b;
    if(array[a1] && array[b1])
        return position[a1]-position[b1];
    else if(!array[a1] && array[b1] )
        return 1;
    else if(array[a1] && !array[b1])
        return -1;
    else
        return a1-b1;
}

int main() {
    int m,n,tmp;
    int s_arrqy[500];
    scanf("%d",&m);
    memset(array,0,1001);
    for(int i=0;i<m;i++){
        scanf("%d",&tmp);
        array[tmp]=1;
        position[tmp]=i;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&s_arrqy[i]);
    qsort(s_arrqy,n,sizeof (int),cmp);
    for(int i=0;i<n;i++)
        printf("%d ",s_arrqy[i]);
    printf("\n");
    return 0;
}
