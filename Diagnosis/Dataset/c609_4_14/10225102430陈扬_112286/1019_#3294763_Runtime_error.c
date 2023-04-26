#include<stdio.h>
int main(){
    int n,arr[1000000],i=0,b[1000000],flag,re,mid;
    int* p=NULL;
    scanf("%d",&n);
    while(n!=EOF){
        arr[++i]=n;
        scanf("%d",&n);
    }
    p=arr;
    for(int j=0;j<i;j++){
        flag=0;
        re=arr[j];
        while(re!=0){
            re/=10;
            flag++;
        }
        b[j]=flag;
    }
    for(int k=0;k<i-1;k++){
        if(b[k]<b[k+1]){
            mid=*(p+k);
            *(p+k)=*(p+k+1);
            *(p+k+1)=mid;
        }
    }
    for(int l=0;l<i-1;l++){
        if(arr[l]>arr[l+1]){
            mid=*(p+l+1);
            *(p+l+1)=*(p+l);
            *(p+l)=mid;
        }
    }
    for(int m=0;m<i;m++){
        printf("%d",arr[m]);
    }
    return 0;
}