#include <stdio.h>
#include <string.h>

int main(){
    unsigned long long num[100];
    memset(num,0,sizeof (num));
    num[0]=0;num[1]=1;
    int k,n;
    scanf("%d %d",&k,&n);
    for(int i=2;i<n;i++){
        for(int j=1;j<k;j++){
            if(i-j<0)
                break;
            num[i]+=num[i-j];
        }
    }
    printf("%llu\n",num[n-1]);
}