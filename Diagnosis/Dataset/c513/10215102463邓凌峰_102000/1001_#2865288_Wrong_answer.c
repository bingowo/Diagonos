#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,N,R;
    scanf("%d",&T);
    int nums[10000][2]={0};
    char ans[10000]={0};
    for(int i=0;i<T;i++){
        scanf("%d%d",&nums[i][0],&nums[i][1]);
    }
    for(int j=0;j<T;j++){
        int n=nums[j][0],r=nums[j][1];
        if(n<0) printf("-");
        n=abs(n);
        int count=0;
        while(n>0){
            int tmp=0;
            tmp=n%r;
            if(tmp<10) ans[count]=tmp+48;
            else ans[count]=tmp+65;
            n=n-tmp*r;
            count++;
        }
        for(int k=count-1;k>=0;k--){
            if(k==0){
                printf("%c\n",ans[0]);
                break;
            }
            printf("%c",ans[k]);
        }
    }

    return 0;
}
