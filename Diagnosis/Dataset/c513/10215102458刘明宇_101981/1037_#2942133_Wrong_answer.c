#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>


int cmp(const void *a, const void*b){
    int *p1,*p2;
    p1 = (int*)a;
    p2 = (int*)b;
    return(*p2 - *p1);
}

int cmp1(const void *a, const void*b){
    int *p1,*p2;
    p1 = (int*)a;
    p2 = (int*)b;
    return(*p1 - *p2);
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int *s = (int *)malloc(100001*sizeof(int));
    int *s1 = (int *)malloc(100001*sizeof(int));

    for(int i = 0;i <n;i++){
        scanf("%d",&s[i]);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    //for(int i = 0;i<n;i++){
    //    printf("%d ",s[i]);
    //}
    int cnt = 0;
    for(int i = 0;i <= n-m;i++){
        int sum = 0;
        for(int j = i;j < i+m;j++){
            sum += (s[i]-s[j]);
        }
        s1[cnt] = sum;
        cnt++;
    }
    qsort(s1,cnt,sizeof(s1[0]),cmp1);

    printf("%d",s1[0]);
    free(s);
}