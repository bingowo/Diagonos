#include <stdio.h>
#include <stdlib.h>

int main(){
    long long int n;
    scanf("%lld",&n);
    unsigned long long int a[n];
    for(int i=0;i<n;i++){
        scanf("%llu",&a[i]);
    }
    long long int temp,m;
    m=n;
    for(int i=0;i<n;i++){
        int ex=0;
        for(int j=0;j<m-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                ex=1;
            }
        }
        m--;
        if (!ex)  //若没有数据的交换，则数据已经排列完毕，跳出循环；
			break;

    }

    long long int sum=0;
    for(int i=0;i<n;i+=2){
        sum+=a[i+1]-a[i];
    }
    printf("%lld",sum);




return 0;
}
