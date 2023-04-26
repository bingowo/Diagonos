#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getNumInBase(int n){
    if(0<=n&&n<=9){
        return n+'0';
    }
    else if(10<=n<=36){
        return n-10+'A';
    }
    return 0;
}
int main()
{
    long long N = 0, R = 0;
    scanf("%lld%lld",&N,&R);
    char res[100]; memset(res,0,100*sizeof(char));
    int resCnt = 0;
    if(N==0){
        printf("0\n");
        return 0;
    }
    while(N!=0){
        long long r = N%R, q = N/R;
        //printf("r = %d, q = %d\n",r,q);
        if(r<0){
            N = q+1;
            r = r-R;
        }
        else{
            N = q;
        }
        res[resCnt++] = getNumInBase(r);
        //printf("1 res = %s\n",res);
    }
    for(int i = 0,j = resCnt-1;i<j;i++,j--){
        char tmp = res[i];
        res[i] = res[j];
        res[j] = tmp;
    }
    printf("%s\n",res);
    return 0;
}
