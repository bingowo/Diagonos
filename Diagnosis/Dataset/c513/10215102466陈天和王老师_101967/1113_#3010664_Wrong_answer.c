
#include <stdio.h>
typedef unsigned long long int llu;
llu A[101]={0,0,1,};
int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;i++){
        int j=i-1;
        int cnt=0;
        while(j>0 && cnt<k){
            A[i]+=A[j];
            j--;
            cnt++;
        }
    }
    printf("%llu\n",A[n]);
}