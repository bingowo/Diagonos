#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,nums[1000]={0};
    char ejz[1000][1000]={'2'};
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&nums[i]);
    }
    for(int j=0;j<T;j++){
        int n=nums[j],count=0;
        while(n>0){
            int tmp=0;
            tmp=n%2;
            if(tmp<10) ejz[j][count]=tmp+48;
            else ejz[j][count]=tmp+48;
            n=n/2;
            count++;
        }

    }
    
    
    
    return 0;
}
