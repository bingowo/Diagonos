#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,length,sum=1,jz,flag=0;
    long long res ;
    char arr[62],brr[62];
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        gets(arr);
        length = strlen(arr);
        brr[0]=arr[0];
        for(int k=0;k<strlen(brr);k++)  {
            for (int j=1;j<length;j++){
                if(arr[j]!=brr[k]){
                    flag++;
                }
            }
            if (flag==strlen(brr)+1){
                brr[k+1]=arr[j];
            }
        }
        jz=strlen(brr)+1;
        for (int l=0;l<length;l++){
            if(l==0){
                res=1;
            }
            else {
                res+=res*jz+l-1;
            }
        }
        printf("%lld",res);
    }
    return 0;
}
