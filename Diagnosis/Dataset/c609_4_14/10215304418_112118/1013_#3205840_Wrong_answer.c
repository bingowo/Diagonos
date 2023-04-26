#include<stdio.h>

int main(){
    long long n;
    scanf("%x",&n);
    int i=0;
    int a[10010];
    while (n!=0){
        a[i]=n%2;
        n=n/2;
        i++;
    }
    long long ansa=0,ansb=0;
    for (int j=i-1;j>=1;j--){
        long long x=-ansa-ansb;
        long long y=ansa-ansb;
        ansa=x;
        ansb=y;
        if (a[j]==1){
            ansa+=-1;
            ansb+=1;
        }
    }
    if (a[0]==1) ansa+=1;
    if (ansa==0&&ansb==0){
        printf("0\n");
    }
    else if (ansa==0){
        if (ansb==1) printf("i\n");
        else printf("%lldi\n",ansb);
    }
    else if (ansb==0){
        printf("%lld\n",ansa);
    }
    else if (ansb<0){
        printf("%lld%lldi\n",ansa,ansb);
    }
    else if (ansb==1){
        printf("%lld+i\n",ansa);
    }
    else printf("%lld+%lldi\n",ansa,ansb);
    return 0;
}
