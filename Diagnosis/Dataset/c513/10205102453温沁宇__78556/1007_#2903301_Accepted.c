#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++){
        int x;
        scanf("%d",&x);
        int ans=0,pre=-1,cnt=0;
        while(x){
            if((x&1)!=pre){
                cnt++;
                ans=fmax(ans,cnt);
            }
            else{
                cnt=1;
            }
            pre=(x&1);
            x>>=1;
        }
        printf("case #%d:\n%d\n",j,ans);
    }

    return 0;
}
