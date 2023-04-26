#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void*b){
    int *p1,*p2;
    p1 = (int*)a;
    p2 = (int*)b;
    return(*p1 - *p2);
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int s[1000001];
    for(int i = 0;i <n;i++){
        scanf("%d ",&s[i]);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i = 0;i<n;i++){
        printf("%d ",s[i]);
    }

}