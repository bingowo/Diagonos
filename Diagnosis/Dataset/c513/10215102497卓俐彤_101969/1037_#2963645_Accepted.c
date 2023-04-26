#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compar(const void*a,const void*b){
    long long int d1,d2;
    d1=*((long long int*)a);
    d2=*((long long int*)b);
    if(d2>d1)return 1;
    else return -1;
}

int main(){
    long long int nums[1000001];
    for(int i=0;i<1000001;i++)nums[i]=0;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)scanf("%lld",&nums[i]);
    qsort(nums,n,sizeof(nums[0]),compar);
    long long int temp=0;
    for(int i=1;i<m;i++)temp+=nums[0]-nums[i];
    long long int min=temp;
    for(int i=1;i<n-m+1;i++){
        temp=temp-(m-1)*nums[i-1]+m*nums[i]-nums[i+m-1];
        min=min<temp?min:temp;
    }
    printf("%lld",min);
    
}
