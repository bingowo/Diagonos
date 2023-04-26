#include<stdio.h>
#include<string.h>

typedef struct {
    long long int element;
} NUMBER;

int main(){
    int T;
    scanf("%d",&T);
    int i,j;
    for(i=0;i<T;i++){
        long long int num,r;
        scanf("%lld",&num);
        NUMBER a[1000];
        int k=0;
        if(num==0) printf("0\n");
        while(num!=0){
            r=num%2333;
            a[k].element=r;
            num=num/2333;
            k++;
        }
		for(j=k-1;j>=0;j--){
			printf("%lld%c",a[j].element,j!=0?' ':'\n');
		}
    }
}