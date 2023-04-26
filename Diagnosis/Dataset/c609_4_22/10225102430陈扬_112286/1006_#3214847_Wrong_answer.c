#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,length,sum=1,jz;
    long long res ;
    char arr[62];
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        scanf("%s",arr);
        length = strlen(arr);
        for (int j=0;j<length;j++){
            for (int k=0;k<length;k++){
                if(arr[j]==arr[k]){
                    sum+=1;
                }
            }
        }
        jz=sum+1;
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
