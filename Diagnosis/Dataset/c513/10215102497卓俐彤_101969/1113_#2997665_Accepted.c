#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct bigint{
    int num[100];
};

void add(int a[],int b[]){
    for(int i=99;i>0;i--){
        a[i]+=b[i];
        if(a[i]>=10){
            a[i]-=10;
            a[i-1]++;
        }
    }
}

int main(){
    int k,n;
    scanf("%d %d",&k,&n);
    struct bigint nums[101];
    memset(nums,0,sizeof(nums));
    nums[2].num[99]=1;
    for(int i=3;i<=n;i++){
        for(int j=0;j<k;j++){
            if(i-j>=2)add(nums[i].num,nums[i-j-1].num);
        }
    }
    int flag=0;
    while(flag<100&&!nums[n].num[flag])flag++;
    if(flag==100)printf("0");
    else{
        for(;flag<100;flag++){
            printf("%d",nums[n].num[flag]);
        }
    }
    printf("\n");
    return 0;
}
