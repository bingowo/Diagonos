#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007
int main()
{
    char w[1100];memset(w,0,1100*sizeof(char));
    scanf("%s",w);
    long long res = 1;
    for(int i = 0;i<strlen(w);i++){
        long long curPosible = 0;
        for(int j = i-1;j<=i+1;j++){
            if(j<0||j>=strlen(w)){
                continue;
            }
            int flag = 1;
            for(int k = i-1;k<j;k++){//有相同字母
                if(w[k]==w[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                curPosible++;
            }
        }
        //printf("%d: possible = %lld\n",i,curPosible);

        res = ((res%MOD)*(curPosible%MOD))%MOD;
        //printf("res = %lld\n",res);

    }
    printf("%lld\n",res);
    return 0;
}
