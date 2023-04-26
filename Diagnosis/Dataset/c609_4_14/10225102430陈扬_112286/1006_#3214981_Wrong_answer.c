#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,length,sum=1,jz,flag,re=1;
    long long res ;
    char arr[62],brr[62];
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        scanf("%s",arr);
        length = strlen(arr);
        brr[0]=arr[0];
          for (int j=1;j<length;j++){
            for(int k=0;k<strlen(brr);k++){
                if(arr[j]!=brr[k]){
                    flag++;
                }
            }
            if (flag==strlen(brr)){
                brr[re]=arr[1];
                re++;
            }
            flag=0;
        }
        jz=strlen(brr)+1;
        printf("%s",brr);
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

