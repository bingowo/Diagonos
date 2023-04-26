#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define maxlen 1000

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int res[maxlen+1]={0};
        int a,n;
        scanf("%d %d",&a,&n);
        int temp=0,carry=0;
        res[maxlen]=1;
        for(int i=0;i<n;i++){
            for(int index=maxlen;index>0;index--){
                temp=res[index]*a+carry;
                carry=0;
                while(temp>9){
                    temp-=10;
                    carry++;
                }
                res[index]=temp;
            }
        }
        temp=0;
        while(!res[temp])temp++;
        printf("case #%d:\n",t);
        for(;temp<maxlen+1;temp++)printf("%d",res[temp]);
        printf("\n");
    }
    return 0;
}

