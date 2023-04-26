#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 50

typedef struct{
    int num[50];
}N;

void add(int*a,int *b){
    for(int i=LEN-1;i;i--){
        a[i]+=b[i];
        for(int k=i;a[k]>9;k--){
            a[k-1]+=a[k]/10;
            a[k]%=10;
        }
    }


}

int main()
{
    int k,n;scanf("%d%d",&k,&n);
    N nums[111]={0};
    nums[12].num[LEN-1]=1;
    for(int i=13;i<=10+n;i++){
        for(int j=1;j<=k;j++){
            add(nums[i].num,nums[i-j].num);
        }
    }
    int idx=0;
    for(;nums[10+n].num[idx]==0 && idx<LEN-1;idx++);
    for(;idx<LEN;idx++){
        printf("%d",nums[10+n].num[idx]);
    }



    return 0;
}

