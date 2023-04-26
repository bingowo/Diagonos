#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{return *(int*)a - *(int*)b;}

int main()
{
    int T;
    scanf("%d",&T); getchar();
    for(int t=0; t<T; ++t) {
        int num[22], cnt=0, flag[22]={0};
        char digit;
        while((digit = getchar()) != '\n')
            num[cnt++] = digit - '0';
        for(int k=cnt-1; k; --k)
            for(int i=k-1; i>=0; --i) {
                if(num[k] > num[i]) {
                    if(flag[i] == 0) flag[i] = num[k];
                    else flag[i] = flag[i]>num[k] ? num[k] : flag[i];
                }
            }
        int k = cnt - 1;
        while(k>=0 && flag[k]==0) --k;
        printf("case #%d:\n",t);
        if(k < 0) {
            qsort(num, cnt, sizeof(int), cmp);
            int i = 0;
            while (num[i] == 0) ++i;
            printf("%d",num[i]);
            num[i] = 0;
        }else {
            for(int i=cnt-1; i>k; --i)
                if(num[i] == flag[k]){
                    num[i] = num[k];
                    num[k] = flag[k];
                    break;
                }
            qsort(num+k+1, cnt-1-k, sizeof(int), cmp);
        }
        for(int i=0; i<cnt; ++i) printf("%d",num[i]);
        printf("\n");
    }
    return 0;
}
