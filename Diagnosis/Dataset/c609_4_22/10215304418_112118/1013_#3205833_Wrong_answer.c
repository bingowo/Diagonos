#include<stdio.h>

int main(){
    int n;
    scanf("%x",&n);
    int i=0;
    int a[10010];
    while (n!=0){
        a[i]=n%2;
        n=n/2;
        i++;
    }
    int ansa=0,ansb=0;
    for (int j=i-1;j>=1;j--){
        int x=-ansa-ansb;
        int y=ansa-ansb;
        ansa=x;
        ansb=y;
        if (a[j]==1){
            ansa+=-1;
            ansb+=1;
        }
    }
    if (a[0]==1) ansa+=1;
    if (ansa==0){
        printf("%di\n",ansb);
    }
    else if (ansb==0){
        printf("%d\n",ansa);
    }
    else if (ansb<0){
        printf("%d%di\n",ansa,ansb);
    }
    else if (ansb==1){
        printf("%d+i\n",ansa);
    }
    else printf("%d+%di\n",ansa,ansb);
    return 0;
}
