#include <stdio.h>
#include <stdlib.h>


int cmp(const void* a, const void* b){
    long long A = *(long long*)a, B = *(long long*)b;
    return A>B? 1 : (A==B ? 0 : -1);
}
int main()
{
    int n = 0, m = 0;
    scanf("%d%d",&n,&m);
    long long nums[n];memset(nums,0,n*sizeof(long long));
    for(int i = 0;i<n;i++){
        scanf("%lld",&nums[i]);
    }
    qsort(nums,n,sizeof(nums[0]),cmp);

//    for(int i = 0;i<n;i++){
//       printf("%lld\n",nums[i]);
//    }
    long long preSum[n-m+1];memset(preSum,0,(n-m+1)*sizeof(long long));
    for(int i = 0;i<m-1;i++){
        preSum[0] += nums[i];
    }
    for(int i = 1;i<n-m+1;i++){
        preSum[i] = preSum[i-1] - nums[i-1] + nums[i-1+m-1];
        //printf("preSum[i-1] = %lld, num[i-1] = %lld, nums[i+1-m] = %lld\n",preSum[i-1],nums[i-1],nums[i-1+m-1]);
    }
//    printf("preSum\n");
//    for(int i = 0;i<n-m+1;i++){
//        printf("%lld\n",preSum[i]);
//    }
    long long res = 0;
    for(int i = 0;i<n-m+1;i++){
        long long curDif = (m-1)*nums[i+m-1] - preSum[i];
        //printf("curDif = %lld, preSum[i] = %lld, nums[i+m-1] = %lld\n",curDif,preSum[i],nums[i+m-1]);
        if(i == 0){
            res = curDif;
        }
        if(curDif<res){
            res = curDif;
        }
    }
    printf("%lld\n",res);
    return 0;
}
