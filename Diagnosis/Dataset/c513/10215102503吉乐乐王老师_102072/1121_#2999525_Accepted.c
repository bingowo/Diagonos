#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void add(int bin[],int n){
    bin[n-1]+=1;
    for(int i=n-1;i>0;i--){
        bin[i-1]+=bin[i]/2;
        bin[i]%=2;
    }
}
int cmp(const void *a,const void *b){
    return *(int*)a>*(int*)b?1:-1;
}
int main(){
    int weight[1000]={0};
   int n;
   int arr[11];
   scanf("%d",&n);
   for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
   }
   int bin[11]={0};
   for(int i=0;i<pow(2,n);i++){
        add(bin,n);
        int tmp=0;
        for(int j=0;j<n;j++){
            if(bin[j]==1)tmp+=arr[j];
        }
        weight[tmp]=1;
        int arr2[11];int ii=0;
        for(int j=0;j<n;j++){
            if(bin[j]==0)arr2[ii++]=arr[j];
        }
        int bin2[11]={0};
        for(int j=0;j<pow(2,ii);j++){
            add(bin2,ii);
            int tmp2=0;
            for(int k=0;k<ii;k++){
                if(bin2[k]==1){
                    tmp2-=arr2[k];
                }
            }
            if(tmp+tmp2>0)weight[tmp+tmp2]=1;
        }
   }
   int idx=0;
   for(int i=0;i<n;i++)idx+=arr[i];
   for(int i=1;i<=idx;i++){
    if(weight[i]==1)printf("1");
    else printf("0");
   }
}
