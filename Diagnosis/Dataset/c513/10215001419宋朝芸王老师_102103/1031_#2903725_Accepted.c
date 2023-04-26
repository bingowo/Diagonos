#include <stdio.h>
#include <stdlib.h>

int cmpa(const void *a, const void *b){ //small - big
    return (*(int*)a - *(int*)b);
}

int cmpd(const void *a, const void *b){ //big - small
    return (*(int*)b - *(int*)a);
}


int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        int *a,*b;
        int n;
        scanf("%d",&n); //dimension n

        a=(int*)malloc(n*sizeof(int)),b=(int*)malloc(n*sizeof(int));
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
        }
        for(int i = 0; i < n; i++){
            scanf("%d",&b[i]);
        }

        qsort(a,n,sizeof(int),cmpa);    //small - big
        qsort(b,n,sizeof(int),cmpd);    //big - small

        long long int ans = 0;
        for(int i = 0; i < n; i++){
            ans += a[i] * b[i];
        }

        printf("case #%d:\n%lld\n",R,ans);

        free(a),free(b);
    }
    return 0;
}
