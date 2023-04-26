#include <stdio.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2){
    return *(int *)p1-*(int *)p2;
}
int gcd(int m,int n){
    if(n==0){
        return m;
    }else{
        return gcd(n,m%n);
    }
}
int main() {
    int n,s;
    scanf("%d%d",&n,&s);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    if(n==1){
        printf("%d",s+a[0]);
    }else{
        double sum=s;
        int sum2=0;
        int h1=0,h2=0,h3=0;
        int sign=0;
        int j=0;
        for(;j<n-1;j++){
            sum = sum+a[j];
            if((sum/(j+1))<=a[j+1]){
                sum2=(int)sum;
                h1 = sum2/(j+1);
                sum2 = sum2%(j+1);
                if(sum2){
                    int r= gcd(j+1,sum2);
                    h2 = sum2/r;
                    h3 = (j+1)/r;
                    sign =1;
                }
                break;
            }
        }
        if(j ==n-1){
            sum2=(int)sum+a[n-1];
            h1 = sum2/(j+1);
            sum2 = sum2%(j+1);
            if(sum2){
                int r= gcd(j+1,sum2);
                h2 = sum2/r;
                h3 = (j+1)/r;
                sign =1;
            }
        }
        if(h1){
            printf("%d",h1);
        }
        if(sign){
            if(h1){
                printf("+");
            }
            printf("%d/%d",h2,h3);
        }
    }
    return 0;
}