#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a, const void *b);


int main()
{
    int n;
    scanf("%d",&n);
    int positive[100000];
    int negative[100000];
    int num;
    int ppl = 0;
    int npl = 0;
    for(int i = 0; i < n; i++){
        scanf("%d",&num);
        if (num < 0){
            negative[npl] = num;
            npl++;
        }else if (num >= 0){
            positive[ppl] = num;
            ppl++;
        }
        //此时ppl和npl代表的是数字的个数而不是最大的下标
    }
    if(ppl > 0){
        qsort(positive,ppl,sizeof(positive[0]),cmp);
    }
    if(npl > 0){
        qsort(negative,npl,sizeof(negative[0]),cmp);
    }
    //按照升序排列两数组
    int ans = 0;
    if ( ppl % 2 != 0 && npl % 2 != 0){
        ans = ans + abs (negative[npl - 1] - positive[0]);
        for (int i = 0; i < npl - 2; i = i + 2){
            ans = ans + abs(negative[i] - negative[i + 1]);
        }
        for(int i = 1; i < ppl - 1; i = i + 2){
            ans = ans + abs(positive[i] - positive[i + 1]);
        }
    }else{
        for (int i = 0; i < npl - 1; i = i + 2){
            ans = ans + abs(negative[i] - negative[i + 1]);
        }
        for(int i = 0; i < ppl - 1; i = i + 2){
            ans = ans + abs(positive[i] - positive[i + 1]);
        }
    }
    printf("%d",ans);
    return 0;
}

int cmp(const void *a, const void *b){
    int i1;
    int i2;
    i1 = *(int *)a;
    i2 = *(int *)b;
    return i1 - i2 > 0 ? 1 : -1;
}
