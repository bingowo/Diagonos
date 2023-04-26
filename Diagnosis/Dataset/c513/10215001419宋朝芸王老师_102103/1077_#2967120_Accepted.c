#include <stdio.h>
#include <stdlib.h>

static int index[1001] = {0};

int cmp(const void *a, const void *b){
    int ia = *(int*)a, ib = *(int*)b;

    if(index[ia] == 0 && index[ib] == 0){
        return ia - ib;
    }

    if(index[ia] == 0 || index[ib] == 0){
        return index[ib] - index[ia];
    }

    return index[ia] - index[ib];

}


int main()
{
    int n,m;
    int cnt = 1;

    scanf("%d",&m);
    for(int k = 0; k < m; k++){
        int temp;
        scanf("%d",&temp);
        index[temp] = cnt++;
    }

    scanf("%d",&n);
    int *b = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d",&b[i]);
    }

    qsort(b,n,sizeof(b[0]),cmp);

    printf("%d",b[0]);
    for(int i = 1; i < n; i++){
        printf(" %d",b[i]);
    }
    printf("\n");

    return 0;
}
