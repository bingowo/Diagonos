#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int map[510];
int cmp(const void *a,const void *b)
{
    int na=*(int *)a;
    int nb=*(int *)b;
    if (map[na]&&map[nb]) {
        return map[na]-map[nb];
    }
    else if(map[na]){
        return -1;
    }
    else if(map[nb]){
        return 1;
    }
    else{
        return na-nb;
    }
    return 0;
}

int main(void)
{
    int m,t;
    scanf("%d",&m);
    for (int i=0; i<m; i++) {
        scanf("%d",&t);
        map[t]=i+1;
    }
    int n;
    scanf("%d",&t);
    int b[n];
    for (int i=0; i<n; i++) {
        scanf("%d",&b[i]);
    }
    qsort(n, n, sizeof(int), cmp);
    for (int i=0; i<n; i++) {
        printf("%d",b[i]);
    }
    return 0;
}
