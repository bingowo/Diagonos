#include <stdio.h>
#include <string.h>
int cmp1(const void *a1,const void *b1){
    int a=*(int *)a1;
    int b=*(int *)b1;
    return b-a;
}
int cmp2(const void *a1,const void *b1){
    int a=*(int *)a1;
    int b=*(int *)b1;
    return a-b;
}
int main(){
    int t,k,i;
    long long int sum;
    scanf("%d",&t);
    for(k=0;k<t;k++){
    	sum=0;
        int n;
        int a[1010];
        int b[1010];
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        qsort(a,n,sizeof(a[0]),cmp1);
        qsort(b,n,sizeof(b[0]),cmp2);
        for(i=0;i<n;i++){
        	sum+=a[i]*b[i];
		}
		printf("case #%d:\n", k);
		printf("%lld",sum);
    }
}
 