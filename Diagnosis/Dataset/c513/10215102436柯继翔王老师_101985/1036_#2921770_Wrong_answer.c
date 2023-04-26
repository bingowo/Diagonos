#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    long long *a1 = (long long*)a,*b1 = (long long*)b;
    unsigned long long s1,s2;
    s1 = llabs(*a1) + llabs(*(a1 + 1));
    s2 = llabs(*b1) + llabs(*(b1 + 1));
    if(s1 == s2)
        if(*a1 != *b1)
            return *a1 > *b1?1:-1;
        else return a1 + 1 > *(b1 + 1);
    else return s1 >s2?-1:1;
}

int main()
{
    int n;
    long long a[100][2];
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%lld%lld",&a[i][0],&a[i][1]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    if((unsigned long long)(llabs(a[1][0] - a[0][0]) + llabs(a[1][1] - a[0][1])) == 0 && (llabs(a[1][0] - a[0][0]) != 0 || llabs(a[1][1] - a[0][1]) != 0))
        printf("18446744073709551616\n");
    else printf("%llu\n",llabs(a[1][0] - a[0][0]) + llabs(a[1][1] - a[0][1]));
    int count = 0;
    for(int i = 0;i < n - 1;i++){
        unsigned long long s =llabs(a[i + 1][0] - a[i][0]) + llabs(a[i + 1][1] - a[i][1]);
        while(s % 2 == 1){
            count++;
            if(s == 1)break;
            if(s % 4 == 1){
                s = (s + 1)/2;
            }else{
                s = (s - 1)/2;
            }
        }
        if(s != 1 && s != 0)break;
    }
    printf("%d",count);
    return 0;
}

