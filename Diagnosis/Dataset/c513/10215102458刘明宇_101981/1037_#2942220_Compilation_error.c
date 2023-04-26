#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>


int cmp(const void *a, const void*b){
    int *p1,*p2;
    p1 = (int*)a;
    p2 = (int*)b;
    if(*p2 > *p1) return 1;
    else return -1;
}

int main()
{
    long long int n,m;
    scanf("%lld %lld",&n,&m);
    long long int *s = (long long int *)malloc(100001*sizeof(long long int));
    for(long long int i = 0;i <n;i++){
        scanf("%lld",&s[i]);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    //for(int i = 0;i<n;i++){
    //    printf("%d ",s[i]);
    //}
    long long int cnt = 0;
    for(long long int i = 0;i <= n-m;i++){
        long long int sum = 0;
        for(long long int j = i;j < i+m;j++){
            sum += (s[i]-s[j]);
        }
        if(cnt == 0){
            s1[cnt] = sum;
            cnt++;
        }
        s1[0] = sum>s1[0]?sum:s1[0];

    }
    printf("%lld",s1[0]);
    free(s);
}

