#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
    long long A = *(long long*)a, B = *(long long*)b;
    return A>B? 1 : (A==B ? 0 : -1);
}

//将n排序，利用前缀差，当前数与前m-1个数差值之和
int main()
{
    int n = 0, m = 0;
    scanf("%d%d",&n,&m);
    //printf("hhh%d\n",m);
    long long nums[n];memset(nums,0,n*sizeof(long long));
    for(int i = 0;i<n;i++){
        scanf("%lld",&nums[i]);
    }
    qsort(nums,n,sizeof(long long),cmp);

    //for(int i = 0;i<n;i++){
    //   printf("%lld\n",nums[i]);
    //}

    long long res = 0;
    for(int i = m-1;i<n;i++){
        long long cur = 0;
        for(int j = i-(m-1);j<i;j++){
            cur += nums[i]-nums[j];
        }
        if(i == m-1){
            res = cur;
        }
        if(cur<res){
            res = cur;
        }
        //printf("cur = %lld\n",cur);
    }
    printf("%lld\n",res);

    return 0;
}
