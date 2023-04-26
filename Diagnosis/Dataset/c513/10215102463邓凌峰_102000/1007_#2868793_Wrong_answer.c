#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,nums[1000]={0};
    char ejz[1000][1000]={'\0'};
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&nums[i]);
    }
    for(int j=0;j<T;j++){
        int n=nums[j],count=0;
        while(n>0){
            int tmp=0;
            tmp=n%2;
            ejz[j][count]=tmp+48;
            n=n/2;
            count++;
        }
        int ans=1,last=1;
        for(int k=1;k<count;k++){
            if(ejz[j][k]!=ejz[j][k-1])ans++;
            else ans=0;
            if(ans>=last) last=ans;
        }
        printf("case #%d:\n",j);
        printf("%d\n",last);

    }



    return 0;
}
