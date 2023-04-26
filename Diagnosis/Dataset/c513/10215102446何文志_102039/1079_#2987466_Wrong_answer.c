#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
    int A = *(int*)a, B = *(int*)b;
    return A-B;
}
int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){

        int n = 0, m = 0;
        scanf("%d%d",&n,&m);
        int num[n];memset(num,0,n*sizeof(char));
        for(int j = 0;j<n;j++){
            scanf("%d",&num[j]);
        }

        int len = n*n;
        int* subNum = (int*)malloc(len*sizeof(int));
        memset(subNum,0,len*sizeof(int));
        int subNumCnt = 0;
        for(int start = 0;start<n;start++){//遍历数组首元素
            for(int end = start;end<n;end++){//遍历数组尾元素
                int curSubNumSum = 0;
                for(int j = start;j<=end;j++){
                    curSubNumSum+=num[j];
                }
                subNum[subNumCnt] = curSubNumSum;
                //printf("cur = %d\n",curSubNumSum);
                subNumCnt++;
            }
        }

        qsort(subNum,subNumCnt,sizeof(subNum[0]),cmp);
        //for(int j = 0;j<subNumCnt;j++){
        //    printf("%d\n",subNum[j]);
        //}
        printf("case #%d:\n",i);
        for(int j = 0;j<m;j++){
            int L = 0,U = 0;
            scanf("%d%d",&L,&U);
            long long res = 0;
            for(int k = L-1;k<U;k++){
                res+=subNum[k];
            }
            //printf("m = %d, res = %lld\n",j, res);
            printf("%d\n",res);
        }
    }
    return 0;
}
