#include <stdio.h>
long long int fuc(int n){
long long int a[100];
a[0]=1;
a[1]=1;
a[2]=2;
a[3]=4;
for(int i=4;i<100;i++){
    a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];

}
return a[n];
}
int main(){
int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld",fuc(n));
        printf("\n");
        }
        return 0;
}

