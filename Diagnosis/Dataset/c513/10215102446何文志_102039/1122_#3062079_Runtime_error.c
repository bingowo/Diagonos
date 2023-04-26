#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ito2333(long long i){
    char* ret = (char*)calloc(1000, sizeof(char));
    long long remain[1000];
    memset(remain, 0, 1000*sizeof(long long));
    int remainCnt = 0;
    if(i==0){
        return "0";
    }
    while(i!=0){
        long long r = i%2333LL;
        remain[remainCnt++] = r;
        i /= 2333LL;
    }
    for(int i = remainCnt-1;i>=0;i--){
        //printf("%lld\n", remain[i]);
        char tmp[100];
        sprintf(tmp, "%lld", remain[i]);
        strcat(ret, tmp);
        if(i!=0){
            strcat(ret, " ");
        }
    }
    return ret;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0; i<T; i++){
        long long n = 0;
        scanf("%lld",&n);
        char* ans = ito2333(n);
        printf("%s\n",ans);
        free(ans);
    }
    return 0;
}
