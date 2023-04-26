#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n,len,sum=0,temp,k=0,num=0;
    char arr;
    int brr[64];
    char* p;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        gets(arr);
        p=arr;
        len=strlen(arr);
        for(int j=0;j<len;j++){
            sum+=*(p+j);
        }
        while(sum!=0){
            temp=sum%2;
            sum=sum/2;
            brr[k++]=temp;
        }
        for(int l=0;l<k;l++){
            if(brr[l]==1){num++;}
        }
        printf("%d/%d",num,strlen(brr));
    }
   
    return 0;
}
